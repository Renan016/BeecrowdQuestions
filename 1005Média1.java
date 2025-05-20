import java.util.Scanner;
import java.io.IOException;

public class Main
{
    public static void main(String[] args) 
    {
        double A, B, solve;
        Scanner input = new Scanner(System.in);
        A = input.nextDouble();
        B = input.nextDouble();
        solve = ((A*3.5) + (7.5*B))/11;
        System.out.printf("MEDIA = %.5f\n", solve);
    }
}