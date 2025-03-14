def permute(nums):
    perms = [[]]   
    for n in nums:
        print('n: ', n, '------------------') 
        new_perms = []
        print('Iteration start. Perms : ',perms)
        for perm in perms:
            print(' '*4, 'perm:',perm)
            for i in range(len(perm)+1):   
                new_perms.append(perm[:i] + [n] + perm[i:])
                print(' '*6, 'perm[:'+str(i)+']:',perm[:i], ' ,n:',n ,' ,perm['+str(i)+':]:',perm[i:])
                print(' '*6, 'new_perms:',new_perms)
        perms = new_perms
        print('Iteration over. Perms : ',perms)
    return perms

print('-------------->result ', permute([1,2,3]))




