## 1. Absolute Must-Know (non-negotiable)

These are table stakes. If you say “I’m an AWS engineer” and don’t know these, it’s a red flag.

### Compute

- **EC2** – Virtual machines (Linux fundamentals matter here)
    
- **Auto Scaling Groups** – Scale EC2 instances automatically
    
- **Elastic Load Balancer (ALB / NLB)** – Traffic distribution
    

### Storage

- **S3** – Object storage (huge deal at AWS)
    
- **EBS** – Block storage for EC2
    
- **EFS** – Network file system
    

### Networking

- **VPC** – Private networking (subnets, routing, gateways)
    
- **Security Groups** – Instance-level firewall
    
- **NACLs** – Subnet-level firewall
    
- **Route 53** – DNS
    

### Identity & Security

- **IAM** – Users, roles, policies (very important)
    
- **KMS** – Encryption keys
    
- **Secrets Manager / Parameter Store**
    

---

## 2. Core Backend / Application Engineer Services

These are what most backend engineers use daily.

### Containers & Orchestration

- **ECS** – AWS-native container orchestration
    
- **EKS** – Kubernetes on AWS
    
- **Fargate** – Serverless containers
    
- **ECR** – Container registry
    

### Databases

- **RDS** – Managed SQL (Postgres, MySQL, Aurora)
    
- **DynamoDB** – NoSQL, massive scale
    
- **ElastiCache** – Redis / Memcached
    
- **Aurora** – AWS-optimized relational DB
    

### Serverless

- **Lambda** – Event-driven functions
    
- **API Gateway** – HTTP APIs
    
- **Step Functions** – Workflow orchestration
    

### Messaging & Streaming

- **SQS** – Message queues
    
- **SNS** – Pub/sub notifications
    
- **Kinesis** – Streaming data
    
- **MSK** – Managed Kafka
    

---

## 3. DevOps / Infra Engineer Essentials

If you touch infra, CI/CD, or reliability.

### Infrastructure as Code

- **CloudFormation** – Native IaC
    
- **CDK** – Infrastructure using code (TypeScript, Python)
    
- (Terraform is common too, even if not AWS-native)
    

### CI/CD

- **CodeCommit**
    
- **CodeBuild**
    
- **CodeDeploy**
    
- **CodePipeline**
    

### Monitoring & Observability

- **CloudWatch** – Logs, metrics, alarms
    
- **X-Ray** – Distributed tracing
    
- **CloudTrail** – Audit logs
    

---

## 4. Security & Compliance (seriously important)

AWS is big on this.

- **IAM Identity Center (SSO)**
    
- **Shield** – DDoS protection
    
- **WAF** – Web application firewall
    
- **GuardDuty** – Threat detection
    
- **Macie** – Data classification
    

---

## 5. Data / Analytics (common at scale)

You don’t need all of these, but knowing the landscape helps.

- **Athena** – SQL over S3
    
- **Glue** – ETL
    
- **Redshift** – Data warehouse
    
- **EMR** – Big data (Spark, Hadoop)
    
- **OpenSearch** – Logs & search
    

---

## 6. Advanced / Core AWS Engineer Territory

These are more relevant to **AWS internal teams**, infra, or senior engineers.

- **Nitro System** – EC2 virtualization backbone
    
- **VPC internals** (ENIs, hyperplane)
    
- **Placement groups**
    
- **Outposts**
    
- **Graviton (ARM)**
    

You’re not expected to _use_ these daily—but understanding them is a big plus.

---

## 7. Minimal “Strong AWS Developer” Checklist

If you want a **tight, realistic target**, aim to be solid in:

✅ EC2  
✅ S3  
✅ VPC  
✅ IAM  
✅ RDS + DynamoDB  
✅ ECS or EKS  
✅ Lambda + API Gateway  
✅ SQS / SNS  
✅ CloudWatch  
✅ CDK or CloudFormation

That alone already puts you above most candidates.

---

## How this maps to roles you asked about earlier

- **Backend Infra Engineer** → EC2, ECS/EKS, DynamoDB, S3, VPC, IAM
    
- **Systems Engineer** → EC2 internals, Nitro, Linux, networking
    
- **Performance Engineer** → EC2 types, Graviton, networking, CloudWatch, X-Ray
    
- **Embedded/Linux Engineer** → Less AWS, more hardware—but EC2 + Nitro knowledge helps