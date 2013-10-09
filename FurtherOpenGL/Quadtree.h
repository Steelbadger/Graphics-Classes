#pragma once

template<typename T, typename X, typename Y = X>
class QuadTree
{
	QuadTree() : depth(0) {
		Initialize();
	}
	QuadTree(int d) : depth(d) {
		Initialize();
	}
	QuadTree(int d, T dat) : depth(d) {
		data = dat;
		Initialize();
	}

	void Store(X xkey, Y ykey, T d) {
		if (
	}

	T& Find (X xkey, Y ykey) {
		if (xkey == x && ykey == y) {
			return data;
		} else if (xkey > x && ykey > y) {
			if (branches[0] != NULL) {
				return branches[0].Find(xkey, ykey);
			} 
		} else if (xkey < x && ykey > y) {
			if (branches[0] != NULL) {
				return branches[1].Find(xkey, ykey);
			} 
		} else if (xkey < x && ykey < y) {
			if (branches[0] != NULL) {
				return branches[2].Find(xkey, ykey);
			} 
		} else if (xkey > x && ykey < y) {
			if (branches[0] != NULL) {
				return branches[3].Find(xkey, ykey);
			} 
		}
	}

	bool Exists(X xkey, Y ykey) {
		if (xkey == x && ykey == y) {
			return true;
		} else if (xkey > x && ykey > y) {
			if (branches[0] != NULL) {
				return branches[0].Exists(xkey, ykey);
			} 
			return false;
		} else if (xkey < x && ykey > y) {
			if (branches[0] != NULL) {
				return branches[1].Exists(xkey, ykey);
			} 
			return false;
		} else if (xkey < x && ykey < y) {
			if (branches[0] != NULL) {
				return branches[2].Exists(xkey, ykey);
			} 
			return false;
		} else if (xkey > x && ykey < y) {
			if (branches[0] != NULL) {
				return branches[3].Exists(xkey, ykey);
			} 
			return false
		}
		return false;
	}

private:
	void Initialize() {
		for (int i = 0; i < 4; i++) {
			branches[i] = NULL;
		}
	}
	X x;
	Y y;
	T data;
	bool used;
	const int depth;
	Quadtree<T, X, Y>* branches[4];
};
