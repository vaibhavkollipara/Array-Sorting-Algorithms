#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;

class Sortings{
private:
	int data[1001]; //data storage array
	int n;//size of the data
	int input; //variable to store user input
	//int inscount; //counts total instructions executed
public:
	void initilize() {//method to initilize and refresh datamembers
		input =0;
		//inscount=0;
		cout << "Choose an operation :\n";//displaying menu
		cout<< "[1] Insertion Sort\n[2] Counting Sort\n[3] Merge Sort\n[4] Randomized Quick Sort\n[5] Exit\n";
		cout << "Enter the index of the operation : ";
		cin >> input;// input from user
		switch (input) {
		case 1:
			insertionSort();
			initilize();
			break;
		case 2:
			countingSort();
			initilize();
			break;
		case 3:
			merge();
			initilize();
			break;
		case 4:
			randomizedQuickSort();
			initilize();
			break;
		case 5:
			return;
		default:
			cout << "Invalid input..\n";
			initilize();

		}

	}
	//function to get data
	void getData() {
			time_t t;
			int i;
			cout << "Enter the size of input (1<= data size <= 1000) :";
			cin >> n;
			if(!(n<1||n>1000)){
			srand(time(&t));
			for (i = 0; i < n; i++) {
				data[i] = getRandomvalue();
			}
			cout << "\nGenerated Data : \n";
			for (i = 0; i < n; i++) {
				cout << data[i] << " ";
			}
			cout<<"\n";
			}else{
				cout<<"Invalid input size...\n";
				getData();

			}

		}
	//function to return a random number
	int getRandomvalue() {
			if (n <= 20) {
				return rand() % 15;//if data size less <=20
			} else {
				if(2==input)
				 return rand() % 99; //data for counting sort
				else
				  return rand();
			}
		}
	//function to display data
	void displayData() {
			int i;
			cout << "\n";
			cout << "Sorted data :\n";//displays data
			for (i = 0; i < n; i++) {
				cout << data[i] << " ";
			}
			if(input!=4)
			 //cout<<"\nInstructions Count : "<<inscount;//displaying instruction count
			cout << "\n\n";
		}
	//function to print stars
	void displayStars() {
			int i, j;
			cout << "\n";
				for (i = 0; i < n; i++) {
					for (j = 0; j < data[i]; j++) {
						cout << "*";
					}
					cout << "\n";
			}

		}
	//function to swap values
	void swap(int a, int b) {//swapping data in array using index values
			int temp = data[a];
			data[a] = data[b];
			data[b] = temp;
	}

	//function for insertion sort
	void insertionSort() {
			int i, j;
			cout << "Insertion Sort..\n";
			getData();
			for (i = n - 1; i >= 0; i--) {
				//inscount++;
				for (j = 0; j < i; j++) {
				//	inscount++;
					if (data[j] > data[j + 1]) {
						swap(j, (j + 1));
						if(n<=20)
						displayStars();
					}
				}
			}
				displayData();

		}

	//functions for merge sort
	void merge() {
			cout << "Merge Sort...\n";
			getData();
			msort(0, (n - 1));
			displayData();
		}

		void merging(int low, int mid, int high) {
			int l1, l2, i;
			int b[n];

			for (l1 = low, l2 = mid + 1, i = low; l1 <= mid && l2 <= high; i++) {
				if (data[l1] <= data[l2])
					b[i] = data[l1++];
				else
					b[i] = data[l2++];
			}

			while (l1 <= mid)
				b[i++] = data[l1++];

			while (l2 <= high)
				b[i++] = data[l2++];

			for (i = low; i <= high; i++)
				data[i] = b[i];
			if(n<=20)
				displayStars();
		}

		void msort(int low, int high) {
			int mid;
			if (low < high) {
			//	inscount++;
				mid = (low + high) / 2;
				msort(low, mid);
				msort(mid + 1, high);
				merging(low, mid, high);
			} else {
				return;
			}
		}


		//function for counting sort
		void countingSort(){
			getData();
			int max =-1;
			int min=101;
			int temp[n];
			for(int i=0;i<n;i++){
				if(data[i]>max)
					max =data[i];
				if(data[i]<min)
					min =data[i];
			}
			int count[max+1];
			for(int i=0;i<=max;i++){//initilize count array
				count[i]=0;
			}

			for(int i=0;i<n;i++){
			//	inscount++;
				count[data[i]]++;
			}

			for(int i=1;i<=max;i++){
			//	inscount++;
				count[i]=count[i]+count[i-1];
			}
			cout<<"\n";

		//printing count sum array
		/*	for(int i=0;i<=max;i++)
				cout<<count[i]<<" ";
			cout<<"\n"; */

			for(int i=0;i<n;i++)
				temp[i]=0;

			for(int i=0;i<n;i++){
			//	inscount++;
				temp[count[data[i]]]=data[i];
				count[data[i]]--;
				//code to print stars if n<=20
								if(n<=20){
									for(int a=0;a<n;a++){
										for(int b=temp[a];b>0;b--){
											cout<<"*";
										}
										cout<<"\n";
									}
									cout<<"\n";
								}
			}
			for(int i=1;i<=n;i++)
				data[i-1]=temp[i];
			displayData();
		}

		//functions for randomized quick sort
		void randomizedQuickSort(){
			getData();
			quickSort(0,n);
			displayData();
		}
		void quickSort( int left, int right)
		{
		    int l = left;
		    int r = right - 1;
		    int size = right - left;

		    if (size > 1) {
		        int pivot = data[rand() % size + l];

		        while (l < r) {
		            while (data[r] > pivot && r > l) {
		                r--;
		            }

		            while (data[l] < pivot && l <= r) {
		                l++;
		            }

		            if (l < r) {
		                swap(l, r);
		                l++;
		            }
		        }
		        if(n<=20)
		        	displayStars();

		        quickSort(left, l);
		        quickSort(r, right);
		    }
		}


};
int main(){
	Sortings s;
	s.initilize();
	return 0;
}
