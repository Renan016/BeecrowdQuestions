import java.util.Scanner;
import java.io.IOException;

public class Main
{
    public static void main(String[] args) 
    {
        int A, B, C, D, solve;
        Scanner input = new Scanner(System.in);
        A = input.nextInt();
        B = input.nextInt();
        C = input.nextInt();
        D = input.nextInt();
        solve = (A * B - C * D);
      System.out.printf("DIFERENCA = %d\n", solve);
    }
}