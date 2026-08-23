//#11
void main() {
    Scanner sc = new Scanner(System.in);

    IO.println("Enter the first Number: ");
    int n1 = sc.nextInt();
    IO.println("Enter the second number: ");
    int n2 = sc.nextInt();
    IO.println("Enter the third number: ");
    int n3 = sc.nextInt();

    if (n1 > n2) {
        if (n1 > n3) {
            IO.println("The biggest number is " + n1);
        } else {
            IO.println("The biggest number is " + n3);
        }
    } else {
        if (n3 > n2) {
            IO.println("The biggest number is " + n3);
        } else {
            IO.println("The biggest number is " + n2);
        }
    }
}
