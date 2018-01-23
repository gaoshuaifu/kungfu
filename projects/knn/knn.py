import csv
import random

from collections import Counter

SPLIT = 0.66
K = 3


def load_data(file_name, split):
    training_data, test_data = [], []
    with open(file_name, 'rb') as f:
        lines = csv.reader(f)
        for line in lines:
            line[:4] = map(float, line[:4])
            if random.random() < split:
                training_data.append(line)
            else:
                test_data.append(line)
        return training_data, test_data


def get_neighbors(training_data, test_sample, k):
    def get_distance(training_sample):
        return sum([(a - b) ** 2 for a, b in zip(training_sample[:-1], test_sample[:-1])])
    return sorted(training_data, key=get_distance)[:k]


def get_prediction(neighbors):
    labels = map(lambda neighbor: neighbor[-1], neighbors)
    counter = Counter(labels)
    return counter.most_common(1)[0][0]


def get_accuracy(test_data, predictions):
    n, correct = len(test_data), 0
    for i in range(len(test_data)):
        if test_data[i][-1] == predictions[i]:
            correct += 1
    return float(correct) / n * 100.0


def main():
    training_data, test_data = load_data("iris.data", SPLIT)
    print("training data size: {}, test data size: {}".format(len(training_data), len(test_data)))

    predictions = []
    for test_sample in test_data:
        neighbors = get_neighbors(training_data, test_sample, K)
        prediction = get_prediction(neighbors)
        print("actual: {}, prediction: {}".format(test_sample[-1], prediction))
        predictions.append(prediction)
    accuracy = get_accuracy(test_data, predictions)
    print("Accuracy: {}".format(accuracy))


if __name__ == "__main__":
    main()
