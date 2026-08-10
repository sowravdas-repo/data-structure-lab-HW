1. BUBBLE SORT 

Idea : compare adjacent and swap it if it is in wrong position and mode
left to right ,move larger element to the most right

example :
  input - 10
           4 3 1 6 8 9 2 99 3 66
    
output : 1 2 3 3 4 6 8 9 66 99 

time complexity : O(n^2)
space complexity : O(1)

---------------------------------

2. SELECTION SORT 

Idea : In each pass ,find the smallest element from the unsorted part and swap it with the first unsorted position,It performs one swap per pass

Example : 
input - int a[8]={4,3,5,2,1,6,10,99};

output - 1 2 3 4 5 6 10 99 

time complexity : O(n^2)
space : O(1)

-----------------------------------
3. COUNTING SORT 
   
   Idea : instead of comparing numbers, count how many times each value appers.Works well within a smaller range of value, as declaring large sizevof array(a[10^10]) is not permited or its inceffiecnt .Also counting sort cann't handle negative value ,as there nothing like nagetive index

   example :
     input : 10
             4 3 3 4 6 99 67 4 1 2   
       
      output : 1 2 3 3 4 4 4 6 67 99

    complexity : time -> O(n+k) ,k denote max element
                 space -> O(k)

        -------------------------
        

