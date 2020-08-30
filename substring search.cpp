for (string t: {"twone", "one", "two"}) {
            for (size_t pos = 0; (pos = s.find(t, pos)) != string::npos;) {
            	// WILL GIVE ALL STARTING INDICES OF THE SUBSTRING AS POS
                /*s[pos + t.length() / 2] = '?';
                r.push_back(pos + t.length() / 2);//for another problems*/
            }
        }