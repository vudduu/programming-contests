import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.Arrays;
import java.util.StringTokenizer;

public class MainA {
    BufferedReader in;
    StringTokenizer str;
    PrintWriter out;

    BigInteger MODBIG = new BigInteger("1000000007");

    String next() throws IOException {
        while ((str == null) || (!str.hasMoreTokens())) {
            str = new StringTokenizer(in.readLine());
        }
        return str.nextToken();
    };

    int nextInt() throws IOException {
        return Integer.parseInt(next());
    };

    public BigInteger conFunc(int n, int r) {
        BigInteger a = BigInteger.ONE;
        BigInteger b = BigInteger.ONE;
        for(int i=1; i<=r ;i++) {
            BigInteger nn = BigInteger.valueOf(n);
            BigInteger xx = BigInteger.valueOf(i);
            n--;
            a = a.multiply(nn);
            b = b.multiply(xx);
        }
        return  a.divide(b).mod(MODBIG);
    }

    int T, N, K;

    void solve() throws IOException{
        T = nextInt();
        for(int cas=1; cas<=T ;cas++) {
            BigInteger res = BigInteger.ZERO;
            N = nextInt();
            K = nextInt();
            int[] a = new int[N];
            for(int i=0; i<N ;i++) {
                a[i] = nextInt();
            }
            Arrays.sort(a);
            for(int i=N-1; i>=K-1 ;i--) {
                BigInteger x = new BigInteger(a[i]+"");
                BigInteger y = conFunc(i, K-1);
                res = res.add(x.multiply(y)).mod(MODBIG);
            }
            System.out.println("Case #" + cas + ": " + res.toString());
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
        new MainA().run();
    }
}
