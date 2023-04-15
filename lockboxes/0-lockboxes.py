#!/usr/bin/python3
"""
Task 0 - Lockboxes module
"""


def canUnlockAll(boxes):

    keys = [0]
    open_boxes = [False for i in range(len(boxes))]

    while len(keys) > 0:
        current_key = keys.pop(0)
        open_boxes[current_key] = True
        for k in boxes[current_key]:
            if not open_boxes[k] and k not in keys:
                keys.append(k)
    return all(open_boxes)
