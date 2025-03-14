# The cake is not a lie!
# ======================

# Commander Lambda has had an incredibly successful week: the first test of the LAMBCHOP doomsday device was completed AND Lambda set a new personal high score in Tetris. To celebrate, the Commander ordered cake for everyone -- even the lowliest of minions! But competition among minions is fierce, and if you don't cut exactly equal slices of cake for everyone you'll get in big trouble. 

# The cake is round, and decorated with M&Ms in a circle around the edge. But while the rest of the cake is uniform, the M&Ms are not: there are multiple colors, and every minion must get ****  exactly the same sequence of M&Ms. ****** Commander Lambda hates waste and will not tolerate any leftovers, so you also want to make sure you can serve the entire cake.

# To help you best cut the cake, you have turned the sequence of colors of the M&Ms on the cake into a string: each possible letter (between a and z) corresponds to a unique color, and the sequence of M&Ms is given clockwise (the decorations form a circle around the outer edge of the cake).

# Write a function called solution(s) that, given a non-empty string less than 200 characters in length describing the sequence of M&Ms, returns the maximum number of equal parts that can be cut from the cake without leaving any leftovers.
# Test cases
# ==========
# Your code should pass the following test cases.
# Note that it may also be run against hidden test cases not shown here.

# -- Python cases --
# Input:
# solution.solution("abcabcabcabc")
# Output:
#     4

# Input:
# solution.solution("abccbaabccba")
# Output:
#     2

# Notes: a-z is unique color, cut string into equal sections of sequences of unique letters, return the number of sections
# valid sequence is any combination of letters that repeat - the smallest sequence possible

# use s.count(tmp) once you find *connected* (e.g. abcabc is connected to each other, but abcaba is not connected) pattern in order to check number of repeats
#**************SOLVED***************

def solution(s):
    sections = 0
    tmp = ""
    pattern = False

    for x in s:
        tmp += x #create pattern
        index = 0
        for i in range(len(s)):
            

            if tmp[index] == s[i]:
                pattern = True
                index += 1
            else:
                pattern = False
                break

            if index == len(tmp):
                index = 0

            
            

        
        if pattern == True and s.count(tmp) > sections:
            sections = s.count(tmp)
            print("CurrFinal: ", tmp)
        
    return sections

def main():
    s = "abccbaabccba"
    print(solution(s))


if __name__ == "__main__":
    main()