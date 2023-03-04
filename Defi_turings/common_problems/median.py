class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        return median(nums1, nums2)

def median(nums1, nums2):
	m = len(nums1)
	n = len(nums2)
	if m==0: return med(nums2, n)
	if n==0: return med(nums1, m)
	L = m + n
	mid = L//2+1
	mil = L%2
	i, j = 0, 0
	seen = 0
	prev, succ = None, None
	while seen < mid:
		prev = succ
		if nums1[i]<nums2[j]:
			succ = nums1[i]
			i+=1
			if i == m:
				k = mid-seen-1
				print(k,k)
				if k == 1:
					prev = succ
					succ = nums2[j+k-1]
				elif k>1:
					prev=nums2[j+k-2]
					succ=nums2[j+k-1]
				seen = mid
		else:
			succ = nums2[j]
			j+=1
			if j == n:
				k = mid-seen-1
				#print(k, i, i+k)
				if k == 1:
					prev = succ
					succ = nums1[i+k-1]
				elif k>1:
					prev=nums1[i+k-2]
					succ=nums1[i+k-1]
				seen = mid
		seen += 1
	if mil:
		return succ
	else:
		return (prev+succ)/2

def med(n1, l):
	num = n1
	if l%2:
		return num[l//2]
	else:
		return (num[l//2-1]+num[l//2])/2