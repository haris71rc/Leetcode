class Solution:
    def reverseString(self, s: list[str]) -> None:
        length = len(s)

        for idx in range(0, int(length/2)):
            s[idx], s[length-1-idx] = s[length-1-idx], s[idx]
        