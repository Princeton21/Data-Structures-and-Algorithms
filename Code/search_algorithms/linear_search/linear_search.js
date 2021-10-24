const linearSearch = (list, item) => {
  for (const [i, element] of list.entries()) {
    if (element === item) {
      return i;
    }
  }
};

linearSearch(["a", "b", "c", "d"], "d"); //3 (index start at 0)
