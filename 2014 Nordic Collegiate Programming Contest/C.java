import java.util.*;
import java.math.*;
public class Main
{
    static BigInteger c[]=new BigInteger[10005];
    public static void main(String args[])
    {
        Scanner cin = new Scanner(System.in);
        BigInteger ans = BigInteger.valueOf(0);
        c[0]=BigInteger.valueOf(1);
        c[1]=BigInteger.valueOf(1);
        int n;
        n=cin.nextInt();

        for(int i=2;i<=n;i++)
        {
            c[i]=c[i-1];
            c[i]=c[i].multiply(BigInteger.valueOf(4*i-2));
            c[i]=c[i].divide(BigInteger.valueOf(i+1));
        }
        for(int i=0;i<=n;i++) ans=ans.add(c[i].multiply(c[n-i]));
        System.out.println(ans);
        //cin.close();
    }
}
