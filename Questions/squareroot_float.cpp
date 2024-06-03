//Why binary search?
//Basically,when we can neglect the left or right part by finding a possible//not possible solution on a 
//sorted answer search space.We can use binary Search.

//When to use selection sort?
//When you have been given a small array which takes less memories. 




#include <iostream>

long long int sqr(int n) {
    int s = 0;
    int e = n;
    long long int mid = s + (e - s) / 2;
    int ans = -1;
    while (s <= e) {
        if (mid * mid == n) {
            return mid;
        }
        if (mid * mid < n) {
            ans = mid;
            s = mid + 1;
        } else {
            e = mid - 1;
        }
        mid = s + (e - s) / 2;
    }
    return ans;
}

double floatroot(int n, int precision, int tempsol) {
    double num = 1;
    double ans = tempsol;
    for (int i = 0; i <= precision; i++) {
        num = num / 10;
        for (double j = ans; j * j < n; j = j + num) {
            ans = j;
        }
    }
    return ans;
}

int floorSqrt() {
    int n;
    std::cout << "Enter the square root you want to find" << std::endl;
    std::cin >> n;

    int tempsol = sqr(n);

    std::cout << "The answer is " << floatroot(n, 3, tempsol) << std::endl;

    return 0;
}

int main() {
    floorSqrt();
    return 0;
}
