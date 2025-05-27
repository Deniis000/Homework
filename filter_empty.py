import sys

def filter():
    while(1):
        line = sys.stdin.readline()
        if not line:
            break
        if line.strip():
            sys.stdout.write(line)

if __name__ == '__main__':
    sys.exit(main())
