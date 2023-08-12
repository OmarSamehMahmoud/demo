From python

RUN mkdir /home/app

COPY ./app /home/app

WORKDIR /home/app

CMD ["python","red.py"]