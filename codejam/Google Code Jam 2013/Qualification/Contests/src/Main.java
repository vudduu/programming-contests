import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.StringTokenizer;

public class Main {
    BufferedReader in;
    StringTokenizer str;
    PrintWriter out;

    String next() throws IOException {
        while ((str == null) || (!str.hasMoreTokens())) {
            str = new StringTokenizer(in.readLine());
        }
        return str.nextToken();
    };

    int nextInt() throws IOException {
        return Integer.parseInt(next());
    };

    // SOLUTION BEGIN
    int T, m;
    String k1, k2;

    BigInteger INF = new BigInteger("9999993919911741000425436580141602948346923222862262837729229258431798216982848864256");
    int[][] cap = new int[110][110];
    BigInteger[][] cost = new BigInteger[110][110];

    void minCostMaxFlow(int numVertices, int s, int t) {
        while(true) {
            int[] prev = new int[numVertices];
            BigInteger[] dist = new BigInteger[numVertices];
            for(int i=0; i<numVertices ;i++) {
                prev[i] = 0;
                dist[i] = INF;
            }

            dist[s] = BigInteger.ZERO;
            while (true) {
                boolean updated = false;
                for (int i = 0; i < numVertices; ++i){
                    if (dist[i].compareTo(INF) < 0) {
                        for (int j = 0; j < numVertices; ++j) {
                            if(cap[i][j] > 0) {
                                if(dist[i].add(cost[i][j]).compareTo(dist[j]) < 0) {
                                    dist[j] = dist[i].add(cost[i][j]);
                                    prev[j] = i;
                                    updated = true;
                                }
                            }
                        }
                    }
                }
                if (!updated) break;
            }
            if (dist[t].compareTo(INF) >= 0) break;
            for(int cur=t; cur!=s ; cur=prev[cur]) {
                --cap[ prev[cur] ][cur];
                ++cap[cur][ prev[cur] ];
            }
        }
    }

    BigInteger isStrPossible(String a, String b, int index) {
        BigInteger res = BigInteger.ZERO;
        BigInteger fact = new BigInteger(6+"");
        for(int i=0; i<a.length() ;i++) {
            char x = a.charAt(i);
            char y = b.charAt(i);
            if(x == y) continue;
            if(x == '?') {
                if(y != '?') {
                    BigInteger p = new BigInteger((y-'a')+"");
                    p = fact.pow(index +a.length() -1 -i).multiply(p);
                    res = res.add(p);
                }
                continue;
            }
            if(y == '?') continue;
            return null;
        }
        return res;
    }

    String mergeStr(String a, String b) {
        String res = "";
        for(int i=0; i<a.length() ;i++) {
            char x = a.charAt(i);
            char y = b.charAt(i);
            if(x == '?') {
                if(y == '?') res = res + 'a';
                else res = res + y;
            }
            else res = res + x;
        }
        return res;
    }

    String solve2() {
        String[] a = new String[m];
        String[] b = new String[m];
        for(int i=0; i<m ; i++) {
            a[i] = "";
            b[i] = "";
        }

        int l = k1.length() / m;
        for(int i=0; i<m ; i++) {
            for(int j=0; j<l ;j++) {
                a[i] += k1.charAt( i*l+j );
                b[i] += k2.charAt( i*l+j );
            }
        }
        for(int i=0; i<m*2+2 ;i++) {
            for(int j=0; j<m*2+2 ;j++) {
                cost[i][j] = BigInteger.ZERO;
                cap[i][j] = 0;
            }
        }

        for(int i=0; i<m ;i++) {
            for(int j=0; j<m ;j++) {
                cost[i+2][j+m+2] = isStrPossible(a[i], b[j], (m-1-i)*l);
                if(cost[i+2][j+m+2] != null)
                    cap[i+2][j+m+2] = 1;
                else
                    cost[i+2][j+m+2] = BigInteger.ZERO;
            }
        }
        for(int i=0; i<m ;i++) {
            cap[0][i+2] = 1;
            cap[i+m+2][1] = 1;
        }

        minCostMaxFlow(m*2+2, 0, 1);

        int maxi = 0;
        String res = new String();
        for(int i=0; i<m ;i++) {
            for(int j=0; j<m ;j++) {
                if(cap[j+m+2][i+2] > 0) {
                    res = res + mergeStr(a[i], b[j]);
                    maxi++;
                }
            }
        }
        if(maxi != m) return "IMPOSSIBLE";
        return res;
    }

    void solve() throws IOException{
        T = nextInt();
        for(int cas=1; cas<=T ;cas++) {
            m = nextInt();
            k1 = next();
            k2 = next();
            System.out.println("Case #" + cas + ": " + solve2());
        }
    }

    BufferedReader reader;
    StringTokenizer tokenizer;
    PrintWriter writer;

    void run() throws IOException {
//        in = new BufferedReader(new InputStreamReader(System.in));
        out = new PrintWriter(System.out);
        in = new BufferedReader(new FileReader("input2.txt"));
//        out.println("output.txt");
        solve();
        out.close();
    }

    public static void main(String[] args) throws IOException {
        new C().run();
    }
}
