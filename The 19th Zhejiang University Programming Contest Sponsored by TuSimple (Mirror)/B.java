import java.util.Scanner;
import java.math.*;

public class Main()
{
    public static void main(String args[])
    {
        Scanner cin = new Scanner(System.in);
        BigInteger n;
        BigInteger two=BigInteger.valueOf(2);
        int t;
        t=cin.nextInt();
        while(t--)
        {
            n=cin.nextBigInteger();
            BigInteger ans = BigInteger.valueOf(0);
            while(n>0)
            {
                n=n.divide(two);
                ans=ans.add(n);
            }
            System.out.println(ans);
        }
    }
}
