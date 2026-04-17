import ollama
import numpy as np

docs = [
    "UTF-8 is a character encoding for Unicode.",
    "ASCII uses 7 bits and supports 128 characters.",
    "Unicode supports characters from many languages.",
    "Encoding errors cause mojibake text."
]

def embed(text):
    response = ollama.embeddings(
        model="embeddinggemma",
        prompt=text
    )
    return np.array(response["embedding"])


# Create embeddings
doc_embeddings = [embed(d) for d in docs]


def cosine(a, b):
    return np.dot(a, b) / (np.linalg.norm(a) * np.linalg.norm(b))


def retrieve(query, k=2):
    q_emb = embed(query)

    scores = [
        cosine(q_emb, emb)
        for emb in doc_embeddings
    ]

    top = np.argsort(scores)[-k:][::-1]

    return [docs[i] for i in top]


def ask(query):

    context = retrieve(query)

    prompt = f"""
    Context:
    {context}

    Question: {query}
    Answer using the context.
    """

    response = ollama.chat(
        model="tinyllama",
        messages=[{"role": "user", "content": prompt}]
    )

    return response["message"]["content"]


print(ask("How many goals has Christiano Ronaldo scored this season?"))