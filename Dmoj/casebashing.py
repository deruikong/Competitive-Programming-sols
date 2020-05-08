import subprocess, random
import string


# brute force solution for answer matching
def runBF(filename, inputs):
    subprocess.call(['wsl', 'g++', '-std=c++14', '-O2', f"{filename}.cpp"])
    process = subprocess.Popen(['wsl', f"./cmake-build-debug/{filename}"], stdin=subprocess.PIPE, stdout=subprocess.PIPE)
    for i in inputs.splitlines():
        if len(i) != 0:
            process.stdin.write(i)
    process.stdin.close()

    return process.communicate()[0].decode("utf-8")


# run test case one by one in C++
def runCpp( filename, t_inputs, t_ans, times, new, file_path="",):
    if new:
        subprocess.call(['wsl', 'g++', '-std=c++14', '-w', '-O2', f"./{file_path}.cpp", "-o", filename])  # compile file
    # main testing
    for case_id in range(times):

        inputs = t_inputs[case_id].encode('utf-8')
        ans = t_ans[case_id]
        process = subprocess.Popen(['wsl', f"./cmake-build-debug/{filename}"], stdin=subprocess.PIPE, stdout=subprocess.PIPE, stderr=subprocess.PIPE)

        # for i in inputs.splitlines():
        #     if len(i) != 0:
        #         process.stdin.write(i+'\n'.encode('utf-8'))
        process.stdin.write("1\n1\n".encode('utf-8'))
        ans = ans.replace('\n', '', 1)
        output = process.communicate()[0].decode("utf-8")

        if output == ans:
            print("TEST CASE %s PASSED!\n" % str(case_id + 1))
        else:
            print("TEST CASE %s FAILED!" % str(case_id + 1))
            print(f"YOUR OUTPUT:\n{output}")
            print(f"CORRECT OUTPUT:\n{ans}", end='\n')
        print("#" * 50, '\n')


# randomized cash bashing
def random_case(filename):
    rand_input ='''100
1
'''
    MAX_N = 100
    # template for random pairs
    # MIN = -100
    # MAX = 100
    # for i in range(MAX_N):
    #     cur = str(random.randint(MIN, MAX))+" "+str(random.randint(MIN, MAX))
    #     cur += "\n"
    #     rand_input += cur
    MAX = int(100)
    for i in range(MAX-5): rand_input += '2\n'
    rand_input += '3 100\n'
    # template for random substring
    # rand_str = ''.join(random.choice(string.ascii_lowercase) for i in range(MAX_N))
    # rand_input += rand_str
    # rand_ans = runBF(filename, rand_input)
    rand_ans = '1'
    runCpp(file, [rand_input], [rand_ans], 1, False)


# input test cases here
# paste input & output in the whitespace
file = "PIB20P3"
randomized = False
if randomized:
    # run randomized cases
    random_case(file+"")
    # run set cases
else:
    test_input = [
'''
aab
abacaaba
''',
'''

''',
'''

''',
'''
    
'''
]
    test_ans = [
'''
2
''',
'''
A = {c,d}
B = {d}
F = {c,d,z}
Q = {}
R = {}
X = {x}
Y = {x}
''',
'''
A = {c,d}
B = {d}
F = {c,d,z}
Q = {}
R = {}
X = {x}
Y = {x}
''',
'''
A = {c,d}
B = {d}
F = {c,d,z}
Q = {}
R = {}
X = {x}
Y = {x}
'''
]
    runCpp(file, test_input, test_ans, 1, True, "")
