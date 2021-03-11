import java.util.Scanner;

public class LoopsAreGreat {
    public static void main(String[] args) {                                                               
         int number; //To be used shortly


        Scanner sc = new Scanner(System.in);
        System.out.print("Enter a size for the array: ");
        int size = sc.nextInt();
        int array[] = ;

        // Now declare and initialise the array.
        if (size >= 0 || size <= 2) {
            array = new int[size];
        }
        else {
            System.out.println("Invalid size.");
        }
        
        
        // The following two lines will prompt and
        // read in a number. You may need to use
        // multiple copies of this to enter
        // data into the array. You can also change
        // it a bit to suit your solution better.
        int i = 0;
        while (i < size) {
            System.out.print("Enter a number: ");
            number = sc.nextInt();
            array[i] = number;

            i++;
        }
        
        // Now print out the array as described.
        int j = 0;
        while(j < size) {    // length is the property of the array  
            System.out.println(array[j]);    
            j++;
        }

        // Leave this down here.
        sc.close();

    }
}