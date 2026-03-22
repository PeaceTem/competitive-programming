import java.util.*;
import java.lang.*;


public class Main{
    static void solve(Scanner sc){
        int n = sc.nextInt();
        List<String> a = new ArrayList<>();

        for(int i = 0; i < n; i++) a.add(sc.next());

        List<Integer> deg = new ArrayList<>(Collections.nCopies(n, 0));
        List<List<Integer>> st = new ArrayList<>();

        for(int i = 0; i < n; i++){
            st.add(new ArrayList<>());
            // deg.add(new)
            for(int j = 0; j < n; j++){
                if(a.get(i).charAt(j) == '1' && i != j){
                    deg.set(i, deg.get(i) + 1);
                    st.get(i).add(j);
                }
            }
        }

        List<List<Integer>> mp = new ArrayList<>();
        for(int i = 0; i < st.size(); i++){
            if(st.get(i).size() > 0){
                mp.add(new ArrayList<>(Arrays.asList(st.get(i).size(), i)));
            }
        }

        Collections.sort(mp, (x, y) -> Integer.compare(x.get(0), y.get(0)));

        // for(int i = 0; i < st.size(); i++){
        //     for(int x : st.get(i)) System.out.printf("%d ", x);
        //     System.out.println();
        // }

        int[][] ans = new int[n - 1][2];
        int p = 0;
        boolean[] used = new boolean[n];
        Arrays.fill(used, false);
        boolean f = true;

        System.out.println();
        for(List<Integer> entry : mp){
            int k = entry.get(0);
            int v = entry.get(1);
            // System.out.println();
            System.out.printf("%d, %d\n", k, v);
            if(!f){
                System.out.println("NO");
                return;
            }

            f = false;
            for(int x : st.get(v)){
                if(used[x]) continue;
                if(p >= n - 1){
                    System.out.println("NO");
                    return;
                }

                f = true;
                used[x] = true;
                ans[p] = new int[]{v, x};
                p++;
            }

        }

        if(p < n - 1){
            System.out.println("NO"); return;
        }
        // bfs and check if all have been visited.

        ArrayDeque<Integer> stk = new ArrayDeque<>();
        int root = -1;
        for(int i = 0; i < deg.size(); i++){
            if(deg.get(i) == n - 1){
                root = i; break;
            }
        }
        

        if(root == -1){
            System.out.println("NO"); return;
        }


        List<Integer>[] adj = new ArrayList[n];
        for(int i = 0;  i < n; i++){
            adj[i] = new ArrayList<>();
        }

        for(int[] e : ans){
            int u = e[0];
            int v = e[1];

            adj[u].add(v);
            adj[v].add(u);
        }

        stk.push(root);
        boolean[] vis = new boolean[n];
        Arrays.fill(vis, false);
        while(!stk.isEmpty()){
            int r = stk.pop();
            vis[r] = true;
            for(Integer x : adj[r]){
                if(vis[x]) continue;
                stk.push(x);
            }
        }

        for(int i = 0; i < vis.length; i++){
            if(vis[i] == false){
                System.out.println("NO"); return;
            }
        }

        System.out.println("YES");
        for(int i = 0; i < n - 1; i++){
            System.out.printf("%d %d\n", ans[i][0] + 1, ans[i][1] + 1);
        }
    }

    public static void main(String[] args){
        int t = 1;
        Scanner sc = new Scanner(System.in);
        t = sc.nextInt();

        while(t-->0){
            solve(sc);
        }
    }
}