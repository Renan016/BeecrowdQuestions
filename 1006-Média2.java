import java.util.Scanner;
import java.io.IOException;

public class Main
{
    public static void main(String[] args) 
    {
        double A, B, C, solve;
        Scanner input = new Scanner(System.in);
        A = input.nextDouble();
        B = input.nextDouble();
        C = input.nextDouble();
        solve = ((A*2) + (3*B) + (C*5))/10;
        System.out.printf("MEDIA = %.1f\n", solve);
    }
}