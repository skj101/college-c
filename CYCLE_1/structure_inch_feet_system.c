#include <stdio.h>

struct Distance {
    int feet;
    int inches;
};

void getDistance(struct Distance *d) {
    printf("Enter feet: ");
    scanf("%d", &(d->feet));
    printf("Enter inches: ");
    scanf("%d", &(d->inches));
}

void addDistances(struct Distance d1, struct Distance d2, struct Distance *result) {
    result->feet = d1.feet + d2.feet;
    result->inches = d1.inches + d2.inches;

    if (result->inches >= 12) {
        result->inches -= 12;
        result->feet++;
    }
}

void displayDistance(struct Distance d) {
    printf("%d feet %d inches\n", d.feet, d.inches);
}

int main() {
    struct Distance distance1, distance2, result;

    printf("Enter details for the first distance:\n");
    getDistance(&distance1);

    printf("\nEnter details for the second distance:\n");
    getDistance(&distance2);

    addDistances(distance1, distance2, &result);

    printf("\nResultant distance: ");
    displayDistance(result);

    return 0;
}
