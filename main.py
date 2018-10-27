#coding: utf-8

import cv2
from pyzbar.pyzbar import decode
import tkinter as tk
import json


def output_json(input) :
    output = {}

    input = [[int(y) for y in x.split(" ")] for x in input.split(":") if x != ""]

    output["length"] = {"vertical" : input[0][0], "width" : input[0][1]}
    del(input[0])

    position = {}
    position["firstAgentPosition"] = {"x" : input[-2][1], "y" : input[-2][0]}
    position["secondAgentPosition"] = {"x" : input[-1][1], "y" : input[-1][0]}
    del(input[-2 :])
    output["position"] = position

    output["point"] = input

    with open("qr.json", "w") as f :
        json.dump(output, f, indent=4)


def show_video(cap, str_window) :
    _, frame = cap.read()
    cv2.imshow(str_window, frame)
    return frame


def select_cam(event) :
    global cam_num, selector
    cam_num = int(event.widget["text"])
    selector.destroy()
    cv2.destroyAllWindows()


cam_num = 0
cap_list = []

for x in range(5) :
    cap = cv2.VideoCapture(x)

    if cap.isOpened() :
        cap_list.append(cap)
        cv2.namedWindow(str(x))
    else :
        break

selector = tk.Tk()
selector.bind('<Escape>', lambda e: selector.quit())

for i, x in enumerate(cap_list) :
        show_video(x, str(i))
        button = tk.Button(text=str(i), width=50)
        button.bind("<Button-1>", select_cam)
        button.pack()

selector.mainloop()

qr_str = ""

while True :
    frame = show_video(cap_list[cam_num], "qr_reader")
    data = decode(frame)

    if len(data) != 0 :
        print("readable!!")
        qr_str_now = data[0][0].decode("utf-8")
        qr_str = qr_str_now if qr_str != qr_str_now else qr_str
        
        
        output_json(qr_str)

    if cv2.waitKey(10) == 27:
            break
