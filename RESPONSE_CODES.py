import enum
class Response(enum.Enum):
    EQUIVALENT = 1
    NOT_EQUIVALENT = 0
    COMPILE_TIME_ERROR = -1
    INVALID_FILE_PATH = -2
    TIME_LIMIT_EXCEEDED = -3
