def to4(num):
    sign = '' if num >= 0 else '-'
    num = abs(num)
    res = []
    while num > 0:
        num, remainder = divmod(num, 4)
        res.append(str(remainder))
    res.append(sign)
    return ''.join(reversed(res)) if len(res) > 1 else '0'


def checked_to4(inp: str):
    inp = inp.strip()
    if not inp.isnumeric() and not inp[1:].isnumeric():
        return "Incorrect input, giving up."
    return to4(int(inp))


def pytests():
    assert checked_to4('123') == '1323'
    assert checked_to4('000123') == '1323'
    assert checked_to4('-123') == '-1323'
    assert checked_to4('   123   ') == '1323'
    assert checked_to4('123456789123456789123456789') == '12120132333133023203230121331330001011330111'
    assert checked_to4('0') == '0'
    assert checked_to4('00000') == '0'
    assert checked_to4('-0') == '0'
    assert checked_to4('') == 'Incorrect input, giving up.'
    assert checked_to4('abc') == 'Incorrect input, giving up.'
    print("All tests passed")


def main():
    inp = input()
    print(checked_to4(inp))


if __name__ == '__main__':
    # main()
    pytests()
