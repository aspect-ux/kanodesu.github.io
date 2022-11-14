#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

/*
void Merge(int array[], int p, int q, int r);
void MergeSort(int array[], int p, int q);

int main()
{
    //int array[7] = {1,3,5,2,4,5,10};
    int array[8] = {5,2,4,7,1,3,2,6};
    int i = 0;

    MergeSort(array, 0, 7);
    //Merge(array, 0, 2, 6);

    for(i; i < 8; i++)
        printf("%d  ", array[i]);
    system("pause:");
    return 0;
}

//合并过程中 p<=q<r
void Merge(int array[], int p, int q, int r)
{
    int n1 = q - p + 1;
    int n2 = r - q;

    int *L;
    L = (int*)malloc(sizeof(int)*n1);
    int *R;
    R = (int*)malloc(sizeof(int)*n2);

    int i = 0;
    int j = 0;

    for(i; i < n1; i++)
        L[i] = array[i + p];
    for(j; j < n2; j++)
        R[j] = array[j + q  +1];

    i = j = 0;

    int k = p;

    while(i!=n1 && j!= n2)
    {
        if(L[i] <= R[j])
            array[k++] = L[i++];
        else
            array[k++] = R[j++];
    }

    while(i < n1)
        array[k++] = L[i++];
    while(j < n2)
        array[k++] = R[j++];

    free(L);
    free(R);
}

void MergeSort(int array[], int p, int q)
{
    if(p < q)
    {
        int r = (p+q)/2;
        MergeSort(array, p, r);
        MergeSort(array, r+1, q);
        Merge(array,p, r, q);
    }
}*/

int main(){
    vector<int> nums = {1,5,7,7,4,4,3},A,B;
    sort(nums.begin(),nums.end());
    int a = nums.size()/2,S1 = 0, S2 = S1;
    for(int i = 0; i < a; i ++)
    {
        if(i > 0 && nums[i] == nums[i-1]) B.push_back(nums[i]);
        else S1 += nums[i];
    }
    for (int j = a; j < nums.size(); j ++)
    {
        if(j > a && nums[j] == nums[j-1]) A.push_back(nums[j]);
        else S2 += nums[j];
    }
    for(int c : B) S2 += c;
    for(int d : A) S1 += d;

    cout<<"WHILE |n1-n2| MIN AND |S1-S2| MAX:"<<endl;
    cout<<"|S1-S2| = "<<abs(S1-S2);
    
    system("pause:");
    return 0;
}