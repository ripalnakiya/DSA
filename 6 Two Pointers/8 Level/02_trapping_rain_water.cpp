/*
    Basically there are three approaches to solve this problem:
$   1. Precomputed Max Arrays (Dynamic Programming style)
#       KeyIdea: Water above a bar depends on the shortest boundary on its left and right.
            
        Precompute maxLeft[i]: tallest bar from 0 to i
        Precompute maxRight[i]: tallest bar from i to n-1
        Sum up trapped water for each index

        For every index i:
        water[i] = min(maxLeft[i], maxRight[i]) - height[i]

~       Time: O(n), Space: O(n)

$   2. Two Pointers (Optimized Space)
#       KeyIdea: You don’t need full arrays if you process from both ends simultaneously.

        Maintain: 
        left, right pointers
        leftMax, rightMax

        Move the pointer with the smaller height, because:
            That side’s max is the limiting factor for water

        If height[left] < height[right], water at left depends only on leftMax, not on the far-right chaos.

~       Time: O(n), Space: O(1)

$   3. Stack-Based Approach (Monotonic Stack)
#       KeyIdea: 
            Water gets trapped between two taller bars, with a shorter bar in between acting as the “valley”.
            The stack keeps indices of bars in decreasing height order.
            When you find a bar taller than the stack’s top, congratulations, you just closed a container.
*/