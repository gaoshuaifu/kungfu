NUMBERS = [
    "", "One", "Two", "Three", "Four", "Five", "Six", "Seven","Eight", "Nine",
    "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen",
    "Seventeen", "Eighteen", "Nineteen"
]
TENS = [
    "", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy",
    "Eighty", "Ninety"
]
class Solution(object):
    def tripletToEnglish(self, num):
        words = []

        if num >= 100:
            words.append(NUMBERS[num / 100])
            words.append("Hundred")
            num %= 100

        if num >= 20:
            words.append(TENS[num / 10])
            words.append(NUMBERS[num % 10])
        else:
            words.append(NUMBERS[num])

        return words

    def numberToWords(self, num):
        if num == 0:
            return "Zero"

        words = []

        if num < 0:
            words += ["Minus"]
            num *= -1

        if num >= 1000 * 1000 * 1000:
            words += self.tripletToEnglish(num / (1000 * 1000 * 1000))
            words += ["Billion"]
            num %= 1000 * 1000 * 1000

        if(num >= 1000 * 1000):
            words += self.tripletToEnglish(num / (1000 * 1000))
            words += ["Million"]
            num %= 1000 * 1000

        if num >= 1000:
            words += self.tripletToEnglish(num / (1000))
            words += ["Thousand"]
            num %= 1000

        if num >= 0:
            words += self.tripletToEnglish(num)

        return " ".join([word for word in words if word != ""])
