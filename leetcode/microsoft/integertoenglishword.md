```
class Solution:
    def numberToWords(self, num: int) -> str:
        
        def one(num):
            switcher = {
                1: 'One ',
                2: 'Two ',
                3: 'Three ',
                4: 'Four ',
                5: 'Five ',
                6: 'Six ',
                7: 'Seven ',
                8: 'Eight ',
                9: 'Nine '
            }
            return switcher.get(num)

        def two_less_20(num):
            switcher = {
                10: 'Ten ',
                11: 'Eleven ',
                12: 'Twelve ',
                13: 'Thirteen ',
                14: 'Fourteen ',
                15: 'Fifteen ',
                16: 'Sixteen ',
                17: 'Seventeen ',
                18: 'Eighteen ',
                19: 'Nineteen '
            }
            return switcher.get(num)
        
        def ten(num):
            switcher = {
                2: 'Twenty ',
                3: 'Thirty ',
                4: 'Forty ',
                5: 'Fifty ',
                6: 'Sixty ',
                7: 'Seventy ',
                8: 'Eighty ',
                9: 'Ninety '
            }
            return switcher.get(num)
        
        
        def two(num):
            if num == 0:
                return ''
            elif num < 10:
                return one(num)
            elif num < 20:
                return two_less_20(num)
            else:
                tenth = num // 10
                unit = num - tenth*10
                if unit:
                    return ten(tenth) + one(unit)
                else:
                    return ten(tenth)
        
        def three(num):
            hundred = num // 100
            if hundred:
                return one(hundred) + 'Hundred ' + two(num - hundred*100)
            else:
                return two(num)
        
        
        if num == 0:
            return 'Zero'
        
        billion = num // 1000000000
        million = (num - (billion * 1000000000)) // 1000000
        thousand = (num - (billion * 1000000000) - (million * 1000000)) // 1000
        rest = num - (billion * 1000000000) - (million * 1000000) - (thousand * 1000)
        
        res = ''
        if billion:
            res += three(billion) + 'Billion '
        
        if million:
            res += three(million) + 'Million '
        
        if thousand:
            res += three(thousand) + 'Thousand '
        
        if rest:
            res += three(rest)
        
        return res[:len(res)-1]
```