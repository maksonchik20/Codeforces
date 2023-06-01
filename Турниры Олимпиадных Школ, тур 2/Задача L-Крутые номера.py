s = input()

s_let = s[0] + s[1] + s[5] + s[6]
s_nums = s[2] + s[3] + s[4] + s[7] + s[8]
# print(s[1].isalpha())
cnt_nums = 1
for i in range(len(s_nums)//2+1):
    if s_nums[i].isdigit():
        if s_nums[4-i].isdigit() and s_nums[i] != s_nums[4-i]:
            cnt_nums = 0
            break
    else:
        if s_nums[4-i] == "*" and s_nums[4-i] == "*":
            cnt_nums = cnt_nums * 10
cnt_let = 1
for i in range(len(s_let)//2):
    if s_let[i].isalpha():
        if s_let[3-i].isalpha() and s_let[i] != s_let[3-i]:
            cnt_let = 0
            break
    else:
        if s_let[3-i] == "*" and s_let[3-i] == "*":
            cnt_let = cnt_let * 26
print(cnt_let * cnt_nums)
        

    
