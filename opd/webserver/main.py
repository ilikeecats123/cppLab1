from fastapi import FastAPI
from fastapi.responses import Response
from queue import Queue
from sys import getsizeof

from random import choice

from os import listdir

from dataclasses import dataclass


app = FastAPI()

@app.get("/get_next_image")
async def get_next_image():
    with open('./images/' + choice(listdir("images")), 'rb') as img_file:
        image_binary = img_file.read()
    return Response(image_binary, media_type="image/png")