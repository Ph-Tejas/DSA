class Solution:
    def isValid(self, s: str) :
        st=[]
        n=len(s)

        for i in range(n):
            if s[i]=='}' or s[i]==')' or s[i]==']':
                if len(st)==0:
                    return False
                
                if s[i]=='}':
                    if st[-1]=='{':
                        st.pop()
                    
                    else:
                        return False


                if s[i]==')':
                    if st[-1]=='(':
                        st.pop()
                    
                    else:
                        return False

                if s[i]==']':
                    if st[-1]=='[':
                        st.pop()
                    
                    else:
                        return False

            else:
                st.append(s[i])

        if len(st)!=0:
            return False

        else:
            return True

                

        