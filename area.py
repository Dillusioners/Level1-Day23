def rectangle_area(length, width):
    """
    Calculate the area of a rectangle.

    Args:
        length (float): The length of the rectangle.
        width (float): The width of the rectangle.

    Returns:
        float: The area of the rectangle.
    """
    area = length * width
    return area


def rectangle_perimeter(length, width):
    """
    Calculate the perimeter of a rectangle.

    Args:
        length (float): The length of the rectangle.
        width (float): The width of the rectangle.

    Returns:
        float: The perimeter of the rectangle.
    """
    perimeter = 2 * (length + width)
    return perimeter


# Example usage
while True:
  try:
    length = int(input("Enter the length:- "))
    width = int(input("Enter the width:- "))
    break
  except:
    print("\n Enter only numbers. \n")
    continue
  

# Calculate the area and perimeter
area = rectangle_area(length, width)
perimeter = rectangle_perimeter(length, width)

# Print the results
print(f"\n The area of the rectangle is {area}.")
print(f"The perimeter of the rectangle is {perimeter}.")
