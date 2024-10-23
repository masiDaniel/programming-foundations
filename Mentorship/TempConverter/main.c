#include <stdio.h>

float degreesToFarhenhit(float degrees){
    float farhenhit = degrees * 9/5 + 32;

    return farhenhit;
}


float FarhenhitToDegrees(float farhenhit){
    float degrees = (farhenhit - 32) * 9/5 ;

    return degrees;
}

int main(){
    float temp;
    float convertedTemp;
    int choice;

    //how do i ensure that the code can take multiple numbers and operations?
    while (choice != 3)
    {
        printf("key in the tempreture, ");
        scanf("%f", &temp);
        printf("1. Convert from Degrees to Farhenit\n");
        printf("2. Convert from Farhenhit to Degrees\n");
        printf("3. Exit\n");
        scanf("%d", &choice);

        if (choice == 1){
            convertedTemp = degreesToFarhenhit(temp);
            printf("[%.2f] degrees is [%.2f] ferhenhit\n", temp, convertedTemp);

        } 
        else if (choice == 2)
        {
            convertedTemp = FarhenhitToDegrees(temp);
            printf("[%.2f] ferhenhit is [%.2f] degrees \n", temp, convertedTemp);
        }else{
            printf("Incorrect choice\n");
            return 1;
        }
    }
    return 0;
}
