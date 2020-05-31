#include "src/sorting.h"
#include "src/recursion.h"
#include "src/comparing.h"
#include "src/BinarySearchTree.cpp"
#include "src/AVLTree.cpp"
//#include "tarea_help/LinkedList.cpp"
#include "src/Trie.cpp"
#include "src/HashTable.cpp"

int main() {
  int arr[10] = {25,15,1,99,16,115,23,45,76,90};
  int* p = arr;
  int* p2 = arr;
  int* p3 = arr;
  int* p4 = arr;
  int* p5 = arr;
  int* p6 = arr;
  cout << "Original array\n";
  imprimir(p, 10);
  cout << "Selection Sort\n";
  selection_sort(p, 10);
  imprimir(p, 10);

  cout << "Bubble Sort\n";
  bubble_sort(p2, 10);
  imprimir(p2, 10);
  cout << "Bubble Sort Optimizado\n";
  bubble_sort_optimized(p3, 10);
  imprimir(p3, 10);
  //delete p;
  //delete p2;
  //delete p3;

  int fact_5 = factorial(5);
  cout<<"Factorial of 5 is: "<<fact_5<<"\n";
  factorial_vizualization(5);

  cout << "Merge Sort\n";
  mergesort_executor(p4, 10);
  imprimir(p4, 10);

  //int a[] = {10, 18, 4, 16, 9, 1, 8, 3, 68};
  //mergesort_executor(a, 10);
  //imprimir(a, 9);

  cout << "Quick Sort\n";
  quicksort_executor(p5, 10);
  imprimir(p5, 10);

  cout << "Quick Sort Medium\n";
  quicksort_executor_medium(p6, 10);
  imprimir(p6, 10);

  /*
  const int SIZE_OF_TESTING_ARRAY = 1000;
  const int RANGE_FROM = 1;
  const int RANGE_TO = 1000;
  const int NUMBER_OF_ALGORITHMS = 6;

  int* input_array = generate_array(SIZE_OF_TESTING_ARRAY, RANGE_FROM, RANGE_TO);
  void (*functions[NUMBER_OF_ALGORITHMS])(int*, int) = {selection_sort, bubble_sort, bubble_sort_optimized, mergesort_executor, quicksort_executor, quicksort_executor_medium};
  string functionNames[NUMBER_OF_ALGORITHMS] = {"Selection Sort", "Bubble Sort", "Optimalized Bubble Sort", "Merge Sort", "Quick Sort", "Median Quick Sort"};

  for (int i = 0; i < NUMBER_OF_ALGORITHMS; i++) {
    cout<<functionNames[i]<<endl;
    (functions[i])(input_array, SIZE_OF_TESTING_ARRAY);
    if (!is_sorted(input_array, SIZE_OF_TESTING_ARRAY)) {
      cout<<"Not sorted!"<<endl;
    } else {
      cout<<"Sorted!"<<endl;
    }
  }
  */

  cout << "Comparing Sorting Algorithms\n";

  const int SIZE_OF_TESTING_ARRAY = 1000;
  const int NUMBER_OF_ARRAYS = 1000;
  const int RANGE_FROM = 1;
  const int RANGE_TO = 1000;

  const int NUMBER_OF_ALGORITHMS = 6;
  string functionNames[NUMBER_OF_ALGORITHMS] = {"Selection Sort", "Bubble Sort", "Optimalized Bubble Sort", "Merge Sort", "Quick Sort", "Median Quick Sort"};
  void (*functions[NUMBER_OF_ALGORITHMS])(int*, int) = {selection_sort, bubble_sort, bubble_sort_optimized, mergesort_executor, quicksort_executor, quicksort_executor_medium};

  for (int i = 0; i < NUMBER_OF_ALGORITHMS; i++) {
    bool all_sorted = true;
    clock_t begin = clock();
    for (int j = 0; j < NUMBER_OF_ARRAYS; j++) {
      int* input_array = generate_array(SIZE_OF_TESTING_ARRAY, RANGE_FROM, RANGE_TO);
      int clone_array[SIZE_OF_TESTING_ARRAY];
      memcpy(clone_array, input_array, 4*sizeof(int));//Copy all numbers from input_array to clone_array  
      (functions[i])(input_array, SIZE_OF_TESTING_ARRAY);
      if (!is_sorted(input_array, SIZE_OF_TESTING_ARRAY)) {
        all_sorted = false;
        cout<<functionNames[i]<<endl;
        cout<<"ERROR this array is not sorted "<<endl;
        print_array(clone_array, SIZE_OF_TESTING_ARRAY);
        cout<<"Returned "<<endl;
        print_array(input_array, SIZE_OF_TESTING_ARRAY);
      }
    }

    clock_t end = clock();
    double seconds = double(end - begin)/CLOCKS_PER_SEC;

    if (all_sorted) {
      cout<<"*******************************************"<<endl;
      cout<<"Finished "<<NUMBER_OF_ARRAYS<<" tests."<<endl;
      cout<<functionNames[i]<<endl;
      cout<<"Took : "<<seconds<<" seconds."<<endl;
    }
  }

  cout << "Binary Search Tree\n";
  BinarySearchTree* bst = new BinarySearchTree();
  bst->insert(30);
  bst->insert(40);
  bst->insert(10);
  bst->insert(50);
  bst->insert(20);
  bst->insert(5);
  bst->insert(35);
  cout<<"\nPrint pre-order\n";
  bst->preorder(bst->getRoot());
  cout<<"\nPrint in-order\n";
  bst->inorder(bst->getRoot());
  cout<<"\nPrint post-order\n";
  bst->postorder(bst->getRoot());
  cout<<"\n";
  bst->print();
  
  cout << "AVL Tree\n";
  AVLTree* avl = new AVLTree();
  avl->insert(30);
  avl->insert(40);
  avl->insert(10);
  avl->insert(50);
  avl->insert(20);
  avl->insert(5);
  avl->insert(35);
  cout<<"\nPrint pre-order\n";
  avl->preorder(avl->getRoot());
  cout<<"\nPrint in-order\n";
  avl->inorder(avl->getRoot());
  cout<<"\nPrint post-order\n";
  avl->postorder(avl->getRoot());
  cout<<"\n";
  cout<<"Search Node: 50\n";
  if (avl->search(50)) {
    cout<<"Found!"<<endl;
  } else {
    cout<<"Not Found!"<<endl;
  }
  cout<<"Delete Node: 50\n";
  if (avl->deleteValue(50)) {
    cout<<"Deleted!"<<endl;
    cout<<"\nPrint pre-order\n";
    avl->preorder(avl->getRoot());
    cout<<"\nPrint in-order\n";
    avl->inorder(avl->getRoot());
    cout<<"\nPrint post-order\n";
    avl->postorder(avl->getRoot());
  cout<<"\n";
  } else {
    cout<<"Not Deleted!"<<endl;
  }
  cout<<"LinkedList\n";
  LinkedList* linkedlist = new LinkedList();
  linkedlist->insert("marvin");
  linkedlist->insert("pepe");
  linkedlist->insert("lucho");
  linkedlist->insert("marbin");
  linkedlist->insert("pep");
  linkedlist->insert("lusho");
  linkedlist->insert("mar");
  linkedlist->print();

  cout<<"\nSearch Node: 'marbin'\n";
  if (linkedlist->search("marbin")) {
    cout<<"Found!"<<endl;
  } else {
    cout<<"Not found!"<<endl;
  }
  cout<<"Delete Node: 'marbin'\n";
  if (linkedlist->deleteValue("marbin")) {
    cout<<"Deleted!"<<endl;
    linkedlist->print();
    cout<<endl;
  } else {
    cout<<"Not deleted!"<<endl;
  }

  cout<<"TrieNode"<<endl;
  Trie* trie = new Trie();
  trie->insert("marvin");
  trie->insert("pepe");
  trie->insert("lucho");
  trie->insert("marbin");
  trie->insert("pep");
  trie->insert("lusho");
  trie->insert("mar");
  cout<<"\nSearch Node: 'marbin'\n";
  if (trie->search("marbin")) {
    cout<<"Found!"<<endl;
  } else {
    cout<<"Not found!"<<endl;
  }
  cout<<"\nSearch Node: 'mariana'\n";
  if (trie->search("mariana")) {
    cout<<"Found!"<<endl;
  } else {
    cout<<"Not found!"<<endl;
  }

  cout<<"Delete: 'marbin'\n";
  if (trie->deleteValue("marbin")) {
    cout<<"Deleted!"<<endl;
    cout<<endl;
  } else {
    cout<<"Not deleted!"<<endl;
  }

  string dict[] =
	{
		"code", "coder", "coding", "codable", "codec", "codecs", "coded",
		"codeless", "codependence", "codependency", "codependent",
		"codependents", "codes", "codesign", "codesigned", "codeveloped",
		"codeveloper", "codex", "codify", "codiscovered", "codrive"
	};
  cout<<"Find the Longest Common Prefix: \n";
  Trie* trie2 = new Trie();
  int size_dict = 21;
  for (int i = 0; i < size_dict; i++) {
    trie2->insert(dict[i]);
  }
  cout<<"The LCP is = "<<trie2->findLCP(dict)<<endl;

  cout<<"HashTable"<<endl;
  HashTable* hashtable = new HashTable(10);
  hashtable->insert("marvin");
  hashtable->insert("pepe");
  hashtable->insert("lucho");
  hashtable->insert("marbin");
  hashtable->insert("pep");
  hashtable->insert("lusho");
  hashtable->insert("mar");
  cout<<"Search Node: 'marbin'\n";
  if (hashtable->search("marbin")) {
    cout<<"Found!"<<endl;
  } else {
    cout<<"Not found!"<<endl;
  }
  cout<<"Delete: 'marbin'\n";
  if (hashtable->deleteValue("marbin")) {
    cout<<"Deleted!"<<endl;
    cout<<endl;
  } else {
    cout<<"Not deleted!"<<endl;
  }

  return 0; 
}