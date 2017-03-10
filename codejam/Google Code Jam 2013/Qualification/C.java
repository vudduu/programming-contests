import java.io.*;
import java.math.BigInteger;
import java.util.StringTokenizer;
import java.util.ArrayList;

public class C {
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

    BigInteger[][] powTen = new BigInteger[102][3];
    BigInteger A, B;
    int res, res2;

    boolean verifyIfFairAndSquare(BigInteger x){
        if(x.compareTo(A) < 0) return false;
        if(x.compareTo(B) > 0) return false;
        String y = x.toString();
        int m = y.length();
        for(int i=0; i < m/2 ;i++){
            if(y.charAt(i) != y.charAt(m-i-1))
                return false;
        }
        return true;
    }

    void dfsPalindrome(int it1, int it2, BigInteger num, int end) {
        int ini = 0;
        if(it1 == 0) ini = 1;
        if(it1 < it2) {
            for(int i=ini; i<=end ;i++) {
                if(i == 2)
                    dfsPalindrome(it1+1, it2-1, num.add( powTen[it1][i].add(powTen[it2][i]) ), 1);
                else
                    dfsPalindrome(it1+1, it2-1, num.add( powTen[it1][i].add(powTen[it2][i]) ), 2);
            }
        }
        else{
            if(it1 == it2) {
                for(int i=ini; i<=end ;i++) {
                    BigInteger x = num.add( powTen[it1][i] ); // TODO analise
                    if(verifyIfFairAndSquare(x.multiply(x))) {
                        res++;
//                        out.println(x + " " + x.multiply(x));
                    }
                }
            }
            else {
                // TODO analise
                if(verifyIfFairAndSquare(num.multiply(num))) {
                    res++;
//                    out.println(num + " " + num.multiply(num));
                }
            }
        }
    }

    void generator() {
        for(int i=1; i<=2 ;i++) {
            powTen[0][i] = BigInteger.valueOf(i);
        }
        for(int i=1; i<=101 ;i++) {
            powTen[i][1] = powTen[i-1][1].multiply(BigInteger.TEN);
            for(int j=0; j<=2 ;j++){
                powTen[i][j] = powTen[i][1].multiply(BigInteger.valueOf(j));
            }
        }
    }

    void recurCad1a(ArrayList<String> cad) {
        boolean flag = true;
        for(String s: cad){
//            out.println(s);
            BigInteger x = new BigInteger(s);
            if(x.compareTo(B) > 0) flag = false;
            if(verifyIfFairAndSquare(x.multiply(x))) {
                res2++;
            }
        }
        if(flag) {
            ArrayList<String> aux = new ArrayList<String>();
            for(int i=0; i<cad.size() ;i++) {
                String s = cad.get(i);
                StringBuffer sf = (new StringBuffer(s)).insert(1, "0").insert(s.length(), "0");
                aux.add(sf.toString());
                sf.setCharAt(1, '1');
                sf.setCharAt(sf.length()-2, '1');
                aux.add(sf.toString());
            }
            recurCad1a(aux);
        }
    }

    void recurCadb(ArrayList<String> cad) {
        boolean flag = true;
        for(String s: cad){
//            out.println(s);
            BigInteger x = new BigInteger(s);
            if(x.compareTo(B) > 0) flag = false;
            if(verifyIfFairAndSquare(x.multiply(x))) {
                res2++;
            }
        }
        if(flag) {
            ArrayList<String> aux = new ArrayList<String>();
            for(int i=0; i<cad.size() ;i++) {
                String s = cad.get(i);
                StringBuffer sf = (new StringBuffer(s)).insert(1, "0").insert(s.length(), "0");
                aux.add(sf.toString());
            }
            recurCad1a(aux);
        }
    }

    void createNumbers() {
        String[] cad0 = {"1", "4", "9"};
        for(int i=0; i<cad0.length ;i++) {
            BigInteger x = new BigInteger(cad0[i]);
            if(verifyIfFairAndSquare(x))
                res2++;
        }
        ArrayList<String> cad1a = new ArrayList<String>();
        cad1a.add("11");
        recurCad1a(cad1a);// 0 and 1

        ArrayList<String> cad1b = new ArrayList<String>();
        cad1b.add("22");
        recurCadb(cad1b);

        ArrayList<String> cad2a = new ArrayList<String>();
        cad2a.add("101");
        cad2a.add("111");
        cad2a.add("121");
        recurCad1a(cad2a);// 0 and 1

        ArrayList<String> cad2b = new ArrayList<String>();
        cad2b.add("202");
        cad2b.add("212");
        recurCadb(cad2b);
    }

    void solve() throws IOException {
        int T = nextInt();
        generator();
        for(int cas=1; cas<=T ;cas++) {
            res = res2 = 0;
            A = new BigInteger(next());
            B = new BigInteger(next());

//            BigInteger aux = BigInteger.valueOf(9); // special case
//            if(aux.compareTo(A) >= 0 && aux.compareTo(B) <= 0) res++;
//            for(int i=1; i<=21 ;i++) {
//                dfsPalindrome(0, i-1, BigInteger.ZERO, 2);
//            }
            createNumbers();
//            if(res != res2) out.println("ERROR");
            out.println("Case #" + cas + ": " + res2);
        }
    }

    void run() throws IOException {
//        in = new BufferedReader(new InputStreamReader(System.in));
//        out = new PrintWriter(System.out);
//        in = new BufferedReader(new FileReader("input.txt"));
        in = new BufferedReader(new FileReader("C-large-1.in"));
        out = new PrintWriter(new FileWriter("output.txt"));
        solve();
        out.close();
    }

    public static void main(String[] args) throws IOException {
        new C().run();
    }
}
