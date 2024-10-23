
def test_ideals(dictionary):
    ranges = {
        'ph': (7.0, 8.0),
        'pCO': (35.0, 36.0),
        'pO': (96.0, 97.0)
    }
    for key, value in dictionary.items():
        if key in ranges:
            min_range, max_range = ranges[key]
            if min_range <= value <= max_range:
                print(f"{key}: {value} is within the range")
            else:
                print(f"{key}: {value} is not within the range")
        else:
            print(f"no range defined for key {key}")


def diagnosis(ideals):
    ph = ideals['ph']
    pCO = ideals['pCO']
    pO = ideals['pO']

    if ph <= 7.3:
        print('low PH')
        if pCO <= 35:
            print('low pCO')
            if pO <= 95:
                print('low pO')
                print('diagnosis [diagnosis 1]\n')
            else:
                print('high pO')
                print('diagnosis [diagnosis 2]\n')
        else:
            print('high pCO')
            if pO < 95:
                print('low pO')
                print('diagnosis [diagnosis 3]\n')
            else:
                print('high pO')
                print('diagnosis [diagnosis 4]\n')
    else:
        print('high ph')
        if pCO <= 35:
            print('low pCO')
            if pO <= 95:
                print('low pO')
                print('diagnosis [diagnosis 5]\n')
            else:
                print('high pO')
                print('diagnosis [diagnosis 6]\n')
        else:
            print('high pCO')
            if pO <= 95:
                print('low pO')
                print('diagnosis [diagnosis 7]\n')
            else:
                print('high pO')
                print('diagnosis [diagnosis 8]\n')


PatientValues = {
    'ph': float(input("Enter pH: ")),
    'pCO': float(input("Enter pCO: ")),
    'pO': float(input("Enter pO: "))
}


test_ideals(PatientValues)

diagnosis(PatientValues)


