double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
    if (nums1Size==0)
        return med(nums2, nums2Size);
    if (nums2Size==0)
        return med(nums1, nums1Size);
    int L = nums1Size+nums2Size;
    int mid = L/2+1, mil=L%2, i=0, j=0;
    int prev, succ, k;
    while (mid>0){
        prev = succ;
        if (nums1[i]<nums2[j]){
            succ = nums1[i++];
            if (i==nums1Size){
                k = mid-1;
                if (k==1){
                    prev = succ;
                    succ = nums2[j+k-1];
                } else if (k>1){
                    prev = nums2[j+k-2];
                    succ = nums2[j+k-1];
                }
                mid = 0;
            }
        } else{
            succ = nums2[j++];
            if (j==nums2Size){
                k = mid-1;
                if (k==1){
                    prev = succ;
                    succ = nums1[i+k-1]:
                }
                else if (k>1){
                    prev = nums1[i+k-2];
                    succ = nums1[i+k-1];
                }
                mid =0;
                }
            }
            mid--;
        }
        if (mil)
            return succ;
        else
            return (prev+succ)/2.
    }

float med(int* n1, int l){
    int m = l/2;
    if (l%2)
        return n1[m];
    else
        return (n1[m-1]+n1[m])/2;
}