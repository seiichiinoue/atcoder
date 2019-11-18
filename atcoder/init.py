import os
import argparse

def create_contest(name):
    os.mkdir(name)
    with open("./_template.cpp", "r") as f:
        source = f.readlines()
    problems = ["a", "b", "c", "d", "e", "f"]
    if name.find("abc") != -1:
        print(int(name.replace("abc", "")))
        if int(name.replace("abc", "")) < 126:
            problems = problems[:4]
    for s in problems:
        with open("./{}/{}.cpp".format(name, s), "w") as f:
            f.writelines(source)

if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument("--name", "-n", type=str)
    args = parser.parse_args()
    create_contest(args.name)