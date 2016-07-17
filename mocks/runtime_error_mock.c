static const char *message = "No error", *file = 0;
static int param = -1, line = -1;

void runtime_error(const char *m, int p, const char *f, int l)
{
    message = m;
    param = p;
    file = f;
    line = l;
}

const char *runtime_error_mock_get_last_error(void)
{
    return message;
}

int runtime_error_mock_get_last_param(void)
{
    return param;
}

void runtime_error_mock_reset(void)
{
    message = "No error";
    param = -1;
}
