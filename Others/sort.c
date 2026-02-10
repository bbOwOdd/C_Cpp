void bubble(int* arr, int size);
void selection(int* arr, int size);
void insertion(int* arr, int size);
int partition(int* arr, int l, int h);
void quick(int* arr, int l, int h);
void merge(int* arr, int l, int m, int r);
void mergeSort(int* arr, int l, int r);
void heapify(int* arr, int size, int i);
void heap(int* arr, int size);
void swap(int *a, int *b);

void swap(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;

    // if(*a == *b) return;
    // *a ^= *b;
    // *b ^= *a;
    // *a ^= *b;
}

void bubble(int* arr, int size){
    for(int i = 0; i < size; i++){
        for(int j = i + 1; j < size; j++){
            if(arr[j] < arr[i]){
                swap(&arr[j], &arr[i]);
            }
        }
    }
}

void selection(int* arr, int size){
    int minIndex;
    for(int i = 0; i < size; i++){
        minIndex = i;
        for(int j = i + 1; j < size; j++){
            if(arr[j] < arr[i]) minIndex = j;
        }
        swap(&arr[i], &arr[minIndex]);
    }
}

void insertion(int* arr, int size){
    int j;
    for(int i = 1; i < size; i++){
        j = i;
        while(j > 0 && arr[j] < arr[j - 1]){
            swap(&arr[j], &arr[j - 1]);
            j--;
        }     
    }
}

int partition(int* arr, int l, int h){
    int pivot = arr[h];
    int i = l - 1;
    for(int j = l; l < h; j++){
        if(arr[j] < pivot){
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[h]);
    return i + 1;
}

void quick(int* arr, int l, int h){
    if(l < h){
        int pivot = partition(arr, l, h);
        quick(arr, l, pivot - 1);
        quick(arr, pivot + 1, h);
    }
}

void merge(int* arr, int l, int m, int r){
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];

    for(i = 0; i < n1; i++) L[i] = arr[l + i];
    for(j = 0; j < n2; j++) R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
    while(i < n1 && j < n2){
        if(L[i] < R[j]){
            arr[k] = L[i];
            i++;
        }else{
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while(i < n1){
        arr[k] = L[i];
        i++;
        k++;
    }

    while(j < n2){
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int* arr, int l, int r){
    if(l < r){
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

void heapify(int* arr, int size, int i){
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    
    if(l < size && arr[l] > arr[largest]) largest = l;
    if(r < size && arr[r] > arr[largest]) largest = r;
    if(largest != i){
        swap(&arr[i], &arr[largest]);
        heapify(arr, size, largest);
    }
}

void heap(int* arr, int size){
    int i;
    for(i = size / 2 - 1; i >= 0; i--) heapify(arr, size, i);
    for(i = size - 1; i >= 0; i--){
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}