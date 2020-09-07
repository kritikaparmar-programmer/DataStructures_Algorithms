# Sorting with Python
# Merge Sort has time complexity of O(nlogn)
# and thus merge sort is preferred over selection, bubble and insertion sort 
# having time compelxity O(n^2)
# Quick sort also have O(nlog(n)) time complexity but it is still not preffered over
# merge sort because of its less stability and in comparision to quick sort 
# even Insertion is stable..


def selection_sort(l):
    for start in range(0, len(l)):
        for i in range(start, len(l)):
            min_pos = start
            if l[i] < l[min_pos]:
                min_pos = i
                (l[start], l[min_pos]) = (l[min_pos], l[start])
    return l


def insertionsort(seq):
    for sliceEnd in range(len(seq)):
        pos = sliceEnd
        while pos > 0 and seq[pos] < seq[pos-1]:
            (seq[pos], seq[pos-1]) = (seq[pos-1], seq[pos])
            pos -= 1
    return seq


def merge(A, B):
    (C, m, n) = ([], len(A), len(B))
    (i, j) = (0, 0)
    while i+j < m+n : 
        if i == m:            # A is empty 
            C.append(B[j])
            j += 1
        elif j == n:
            C.append(A[i])
            i += 1
        elif A[i] <= B[j]:
            C.append(A[i])
            i += 1
        elif B[j] <= A[i]:
            C.append(B[j])
            j += 1
    return C

def mergeSort(A, left, right):   # A[left:right]
    if right-left <= 1:
        return (A[left:right])

    if right-left > 1:
        mid = (right+left) // 2
        L = mergeSort(A, left, mid)
        R = mergeSort(A, mid, right)

    return merge(L, R)


def quickSort(A, l, r):  # A[l:r]
    if r-l <= 1:
        return ( )

    yellow = l + 1
    for green in range(l+1, r):
        if A[green] < A[l]:
            (A[yellow], A[green]) = (A[green], A[yellow])
            yellow += 1

    (A[l], A[yellow-1]) = (A[yellow-1], A[l])

    quickSort(A, l, yellow-1)
    quickSort(A, yellow, r) 
    return A


def bubbleSort(A):
    for i in range(0, len(A)):
        for j in range(0, len(A)-i-1):  # -1 beacause every time we will leave the last one as we go through one pass
            if (A[j] > A[j+1]):
                (A[j], A[j+1]) = (A[j+1], A[j])
    return A


l1 = [2, 5, 1, 10, 7]
list1 = selection_sort(l1)
print(list1)

l2 = [2, 5, 1, 10, 7, 20, 14]
list2 = insertionsort(l2)
print(list2)

arr1 = [2, 5, 1, 0, 7, 4, 9, 6]
arr = mergeSort(arr1, 0, 7)
print(arr)

arr2 = [10, 7, 3, 1, 9, 6]
e = quickSort(arr2, 0, len(arr2))
print(e)

arr3 = [12, 10, 20, 6, 2]
i = bubbleSort(arr3)
print(i)
