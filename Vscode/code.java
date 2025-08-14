import java.util.Scanner;

public class code{

    public static void main(String [] args){

        int n1,n2;
        String p1,p2;

        Scanner input = new Scanner(System.in);

        n1 = input.nextInt();
        p1 = input.nextLine();
        input.nextLine();
        n2 = input.nextInt();
        input.nextLine();
        p2 = input.nextLine();

        int counter = 0;

        String [] a1 = p1.split("");
        String [] a2 = p2.split("");

        if(a1[0] == a2[0]){
        while(a1[counter] == a2[counter]){

            counter++;

        }
        }

        System.out.println(counter);

    }

}