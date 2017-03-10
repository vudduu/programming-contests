import java.math.BigInteger;

public class PenguinSledding {

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
        return a.divide(b);
    }

    public long countDesigns(int n, int[] che1, int[] che2) {
        int m = che1.length;
        int[] G = new int[52];
        for(int i=0; i<m ;i++){
            if(che1[i] > che2[i]) {
                int xx = che1[i];
                che1[i] = che2[i];
                che2[i] = xx;
            }
            G[che2[i]]++;
            G[che1[i]]++;
        }
        BigInteger r = BigInteger.valueOf(1 + m);
        for(int i=1; i<=n ;i++) {
            int t = G[i];
            for(int j=2; j<=t ;j++) {
                r = r.add(conFunc(t, j));
            }
            for(int j=i+1; j<n ;j++) {
                for(int k=j+1; k<n ;k++) {
                    int aux = 0;
                    for(int x=0; x<m ;x++) {
                        int aux2 = 0;
                        if(che1[x] == i) aux2++;
                        if(che1[x] == j) aux2++;
                        if(che1[x] == k) aux2++;
                        if(che2[x] == i) aux2++;
                        if(che2[x] == j) aux2++;
                        if(che2[x] == k) aux2++;
                        if(aux2 == 2) aux++;
                    }
                    if(aux == 3)
                        r.add(BigInteger.ONE);
                }
            }
        }
        return r.longValue();
    }
}
