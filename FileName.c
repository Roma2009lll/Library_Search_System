#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
struct Book {
	char name[100];
	char author[50];
	int isbn;
	int date;
	char catecory[30];


};
struct Test {
	int isbn;

};
int comp0 = 0;
int comp1 = 0;
int comp2 = 0;
void gen_book(struct Book** bp, int* count) {
	*bp = (struct Book*)malloc(sizeof(struct Book) * (*count));
	if (*bp == NULL) {
		printf("Memmory allocation failed\n");
		return;

	}
	char* authors[] = {
		"Stephen King",
		"J.K. Rowling",
		"George Orwell",
		"Agatha Christie",
		"J.R.R. Tolkien"
	};

	char* categories[] = {
		"Fiction",
		"Science",
		"History",
		"Fantasy",
		"Biography",
		"Mystery",
		"Romance"
	};
	srand(time(NULL));
	for (int i = 0; i < (*count); i++) {
		
		(*bp)[i].isbn=1000 + i ;
        sprintf((*bp)[i].name, "Book%d", i + 1);
		strcpy((*bp)[i].author, authors[rand() % 5]);
		(*bp)[i].date=1990 + (rand() % 35);
		strcpy((*bp)[i].catecory, categories[rand() % 7]);


		

	}
	


}
void show_all(struct Book* bp, int count) {
	if (count == 0) {
		printf("No data here\n");
		return;

	}
	for (int i = 0; i < count; i++) {

		printf("Book %d:\n", i + 1);
		printf("  ISBN:     %d\n", bp[i].isbn);
		printf("  Title:    %s\n", bp[i].name);
		printf("  Author:   %s\n", bp[i].author);
		printf("  Year:     %d\n", bp[i].date);
		printf("  Category: %s\n\n", bp[i].catecory);
	}
}
int lein_ser(struct Book* bp, int count,const char* target) {
	if (count == 0) {
		printf("No data here\n");
		return -1;

	}
	
	for (int i = 0; i < count; i++) {
		
		comp0++;
		if (strcmp(bp[i].name, target) == 0) {
			printf("Found in %d comprasions\n", comp0);
			return i;
			
		}
	}
	printf("Not found after %d comprasions\n", comp0);
	return -1;


	
}
int bin_ser(struct Book* bp,int l,int r,int target1) {
	
	int mid = l + (r - l) / 2;
	
	if (l > r) {
		printf("Not found after %d comprasions\n", comp1);
		return -1;
	}
	comp1++;
	if (bp[mid].isbn == target1) {
		printf("Found in %d comprasions\n", comp1);
		return mid;

	}
	else if (target1< bp[mid].isbn) {
		return  bin_ser(bp, l, mid - 1, target1);

	}
	else {
		return  bin_ser(bp, mid+1,r, target1);

	}

}
int bin_ser_yaer(struct Book* bp, int l, int r, int target2) {
	
	
	int mid = l + (r - l) / 2;
	if (l > r) {
		printf("Not found after %d comprasions\n", comp2);
		comp2 = 0;
		return -1;
	}
	comp2++;
	
	
	if (bp[mid].date == target2) {
		printf("Found in %d comprasions\n", comp2);
		return mid;

	}
	else if (target2 < bp[mid].date) {
		return bin_ser_yaer(bp, l, mid - 1, target2);

	}
	else {
		return  bin_ser_yaer(bp, mid + 1, r, target2);
		
	}

}
void swap(struct Book* a, struct Book* b) {
	
	struct Book temp = *a;
	*a = *b;
	*b = temp;

}
int pat_by_year(struct Book* bp, int l, int h) {
	int pivot = bp[h].date;
	int i = l - 1;
	for (int j = l; j <= h - 1; j++) {
		if (bp[j].date < pivot) {
			i++;
			swap(&bp[i], &bp[j]);

		}
	}
	swap(&bp[i + 1], &bp[h]);
	return i + 1;

}
void quickSort(struct Book* bp, int l, int h) {
	if (l < h) {
		int pi = pat_by_year(bp, l, h);
		quickSort(bp, l, pi - 1);
		quickSort(bp, pi + 1, h);

	}
}
int linear_search_isbn(struct Test* bo, int count9, int tar) {
	for (int i = 0; i < count9; i++) {
		if (bo[i].isbn == tar) {
			return i;  
		}
	}
	return -1;  
}
int bin_ser1(struct Test* bo, int l, int r, int tar) {

	int mid = l + (r - l) / 2;

	if (l > r) {
		
		return -1;
	}
	
	if (bo[mid].isbn == tar) {
		
		return mid;

	}
	else if (tar< bo[mid].isbn) {
		return  bin_ser1(bo, l, mid - 1, tar);

	}
	else {
		return  bin_ser1(bo, mid + 1, r, tar);

	}

}
void time12() {
	int count9 = 100000000;
	int tests = 100000;
	struct Test* bo = (struct Test*)malloc(sizeof(struct Test) * count9);
	if (bo == NULL) {
		printf("Memory allocation failed!\n");
		return;
	}
	for (int i = 0; i < count9; i++) {
		bo[i].isbn = 1000 + i;  
	}
	clock_t start = clock();
	for (int i = 0; i < tests; i++) {
		int res1 = linear_search_isbn(bo, count9, 10999);
	}
	clock_t end = clock();

	
	double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
	clock_t start1 = clock();
	for (int i = 0; i < tests; i++) {
		int res2 = bin_ser1(bo,0, count9 - 1,10999);
	}
	clock_t end1 = clock();
	double time_taken1 = (double)(end1 - start1) / CLOCKS_PER_SEC;
	printf("Time(with lin ser): %.6f seconds\n", time_taken);
	printf("Time(with bin ser): %.6f seconds\n", time_taken1);
	printf("Binary is %.2fx FASTER!\n", time_taken / time_taken1);
	printf("Amount of data:%d\n", count9);
	printf("Amount of tests:%d\n", tests);


}
void visualize_comparisons() {
	int max = (comp0 > comp1) ? comp0 : comp1;
	if (max == 0) {
		printf("Linear  [                                                  ] 0\n");
		printf("Binary  [                                                  ] 0\n");
		return;
	}
	int lin = (comp0 * 50) / max;
	int bin = (comp1 * 50) / max;
	printf("Linear  [");
	for (int i = 0; i < 50; i++) {
		if (i < lin) {
			putchar('#');
		}
		else {
			putchar(' ');
		}


	}
	printf("] %d\n", lin);
	printf("Binary  [");
	for (int i = 0; i < 50; i++) {
		if (i < bin) {
			putchar('#');
		}
		else {
			putchar(' ');
		}


	}
	putchar('|');
	printf("] %d\n", bin);

}
void show_menu(int count) {
	
		printf("\n");
		printf("+========================================+\n");
		printf("|      LIBRARY SEARCH SYSTEM             |\n");
		printf("+========================================+\n");
		printf("Database: [%d] books loaded\n\n", count);
		printf("1. Search by Title (Linear)\n");
		printf("2. Search by ISBN (Binary)\n");
		printf("3. Search by Year (Binary)\n");
		printf("4. Speed Comparison (Linear vs Binary)\n");
		printf("5. Visualize Results\n");
		printf("6. Generate New Database\n");
		printf("7. Show all data\n");
		printf("8. About Algorithms\n");
		printf("0. Exit\n");
		printf(">> ");
}




int main() {
	int count = 1000;
	struct Book* bp = NULL;
	int op;
	char target[100];
	int target1;
	int target2;
	int n;
	gen_book(&bp, &count);
    
	while (1) {
		show_menu(count);
		scanf_s("%d", &op);
		getchar();
		switch(op) {
			case 1:
			
			printf("Enter book name: ");
			gets_s(target, 100);
			int res = lein_ser(bp, count, target);
			if (res != -1) {
				printf("Book %d:\n", res + 1);
				printf("  ISBN:     %d\n", bp[res].isbn);
				printf("  Title:    %s\n", bp[res].name);
				printf("  Author:   %s\n", bp[res].author);
				printf("  Year:     %d\n", bp[res].date);
				printf("  Category: %s\n\n", bp[res].catecory);
			}
		    break;	
			case 2:
				
				printf("Enter ISBN: ");
				scanf_s("%d", &target1);
				getchar();
				int res1 = bin_ser(bp, 0, count - 1, target1);
				if (res1 != -1) {
					printf("Book %d:\n", res1 + 1);
					printf("  ISBN:     %d\n", bp[res1].isbn);
					printf("  Title:    %s\n", bp[res1].name);
					printf("  Author:   %s\n", bp[res1].author);
					printf("  Year:     %d\n", bp[res1].date);
					printf("  Category: %s\n\n", bp[res1].catecory);
				}
				break;
				
			case 3:
				printf("Sorting books by year first...\n"); 
				quickSort(bp, 0, count - 1);               
				printf("Sorted!\n");                      
				printf("Enter Year: ");
				scanf_s("%d", &target2);
				getchar();
				int res2 = bin_ser_yaer(bp, 0, count - 1,target2);
				if (res2 != -1) {
					printf("Book %d:\n", res2 + 1);
					printf("  ISBN:     %d\n", bp[res2].isbn);
					printf("  Title:    %s\n", bp[res2].name);
					printf("  Author:   %s\n", bp[res2].author);
					printf("  Year:     %d\n", bp[res2].date);
					printf("  Category: %s\n\n", bp[res2].catecory);
				}
				break;
			case 4:
				time12();
				break;
			case 5:
				visualize_comparisons();
				break;
			case 6:
				free(bp);
				printf("How many books?\n");
				scanf_s("%d", &n);
				gen_book(&bp,&n);
				count = n;
				printf(" Generated %d books!\n", n);
				break;
			case 7:
				show_all(bp, count);
				break;
			case 8:
				printf("\nABOUT SEARCH ALGORITHMS:\n\n");
				printf("Linear Search O(n):\n");
				printf("  - Checks every element one by one\n");
				printf("  - Simple but slow on large data\n");
				printf("  - Works on unsorted data\n\n");
				printf("Binary Search O(log n):\n");
				printf("  - Divides search space in half each time\n");
				printf("  - Very fast on large data\n");
				printf("  - Requires sorted data\n\n");
				break;
			case 0:
				printf("\nThank you for using Library Search System!\n");
				return 0;
			default:
				printf("Invalid choice!\n");








				

		}

	}
	

		


	

	

	
	

	
			
		

	


	
	


	
	
		

	



	free(bp);

	return 0;



}