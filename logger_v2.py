import sys
import datetime

class Logger:
    def __init__(self, stream = sys.stderr, time_format='%Y-%m-%d %H:%M:%S'):
        self.stream = stream
        self.time_format = time_format

    def log(self, message):
        time = datetime.datetime.now().strftime(self.time_format)
        self.stream.write(f'[{time}] {message}\n')

if __name__ == '__main__':
    out_stream = sys.stderr
    time_formatter = '%Y-%m-%d %H:%M:%S'
    logger = Logger(out_stream, time_formatter)
    logger.log('message for logging')
