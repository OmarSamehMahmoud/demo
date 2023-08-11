from python

RUN mkdir /home/app

COPY ./home/app

CMD["python","red.py"]