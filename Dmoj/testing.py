import subprocess
from tkinter import *


class main:
    def __init__(self, master):
        self.master = master
        master.title("Case Bashing Tools")
        self.lbl = Label(master, text = "REEEEEEEEEEEEEEEEEEEEE").pack()

        self.file = Entry(master, text = "Filename: ").pack()
        self.recompile = Checkbutton(master, text = "Recompile").pack()
        self.add = Entry(master, text = "Number of Cases: ").pack()


    def runcpp(filename, inputs, ans, new):
        if new: subprocess.call(['wsl', 'g++', '-O2', f"{filename}.cpp"])
        process = subprocess.Popen(['wsl', f"./cmake-build-debug/{filename}"], stdin=subprocess.PIPE,
                                   stdout=subprocess.PIPE)
        for i in inputs.split():
            process.stdin.write(i.encode('utf-8'))
        process.stdin.close()
        if process.communicate()[0].decode("utf-8") == ans:
            print("Pass test case")
        else:
            print(process.communicate()[0].decode("utf-8"))
            print(ans)


if __name__ == '__main__':
    window = Tk()
    gui = main(window)
    window.mainloop()