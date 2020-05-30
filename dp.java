import java.util.*;

public class dp{
    public static void main(String[] args)
    {
     solve();
    }
    public static void solve()
    {
    System.out.println(fibousing_dp(9));
    }
    public static int fibousing_dp(int n, int[][] f)
    {
        int[][] f={{1,1},{1,0}};
     if(n==0)
     return 0;
     power(f,n-1);
     return f[0][0]; 
    }
    public static void power(int[][] a,int[][] i,int pow)
    { 
        power(a,i,pow/2);
        multiply(a,a);

        if(pow%2 !=0)
        multiply(a,i);
    }

}