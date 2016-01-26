#ifndef IO_H
#define IO_H

//@ #include "gcf.gh"

// TODO: I want to put here things that does not have a body (i.e. needs a soundness proof),
//       or that remains the same always anyways (if any).
//       Find out what fits here and what not.


/*@
#define act_t int
#define progress_t list<act_t>

inductive id =
  id_init(int family)
  | id_split_left(id)
  | id_split_right(id)
  | id_join(id left, id right)
;

fixpoint int id_family(id id) {
  switch(id){
    case id_init(family): return family;
    case id_split_left(sub): return id_family(sub);
    case id_split_right(sub): return id_family(sub);
    case id_join(left, right): return id_family(left);
  }
}
fixpoint bool id_is_split(id id) {
  switch(id){
    case id_split_left(sub): return true;
    case id_split_right(sub): return true;
    default: return false;
  }
}
fixpoint bool id_is_join(id id) {
  switch(id){
    case id_join(sub1, sub2): return true;
    default: return false;
  }
}
fixpoint bool id_is_init(id id) {
  switch(id){
    case id_init(fam): return true;
    default: return false;
  }
}
fixpoint id id_parent1(id id) {
  switch(id){
    case id_join(sub1, sub2): return sub1;
    case id_split_left(sub): return sub;
    case id_split_right(sub): return sub;
    case id_init(fam): return default_value<id>;
  }
}
fixpoint id id_parent2(id id) {
  switch(id){
    case id_join(sub1, sub2): return sub2;
    default: return default_value<id>;
  }
}


inductive place = no_place | place(id id, place parent1, place parent2, progress_t progress);
fixpoint id place_id(place t1) {
  switch(t1) {
    case no_place: return default_value<id>;
    case place(id, parent1, parent2, progress): return id;
  }
}
fixpoint progress_t place_progress(place t1) {
  switch(t1) {
    case no_place: return default_value<progress_t>;
    case place(id, parent1, parent2, progress): return progress;
  }
}
fixpoint place place_parent1(place t1) {
  switch(t1) {
    case no_place: return default_value<place>;
    case place(id, parent1, parent2, progress): return parent1;
  }
}
fixpoint place place_parent2(place t1) {
  switch(t1) {
    case no_place: return default_value<place>;
    case place(id, parent1, parent2, progress): return parent2;
  }
}
fixpoint place place_io(place t1, act_t act) {
  return place(place_id(t1), place_parent1(t1), place_parent2(t1), append(place_progress(t1),{act}));
}
fixpoint place place_join(place t1, place t2) {
  return place(id_join(place_id(t1), place_id(t2)), t1, t2, nil);
}

predicate token(place t1; int family) =
  family == id_family(place_id(t1))
  &*& [1/2]gcf_instance<id, progress_t>(family, place_id(t1), place_progress(t1))
  &*& id_is_split(place_id(t1)) ?
    [1/2]token(place_parent1(t1), family)
    &*& id_parent1(place_id(t1)) == place_id(place_parent1(t1))
  : id_is_join(place_id(t1)) ?
    token(place_parent1(t1), family)
    &*& token(place_parent2(t1), family)
    &*& id_parent1(place_id(t1)) == place_id(place_parent1(t1))
    &*& id_parent2(place_id(t1)) == place_id(place_parent2(t1))
  : emp;

predicate split(place t1, place t2, place t3) =
  // TODO there is overlap in information: id of t1 is related to id of t2. Can this lead to issues? Can we remove some double info?
  t2 == place(id_split_left(place_id(t1)), t1, no_place, nil) &*&
  t3 == place(id_split_right(place_id(t1)), t1, no_place, nil)
  &*& [1/2]gcf_instance<id, progress_t>(id_family(place_id(t1)), place_id(t2), nil)
  &*& [1/2]gcf_instance<id, progress_t>(id_family(place_id(t1)), place_id(t3), nil);
  
// TODO: maybe make opaque to avoid construction of "wild joins"?
predicate join(place t1, place t2, place t3) =
  //t1 != t2 // TODO I think we actually don't need this is in the join lemma, so removed.
  t3 == place_join(t1, t2)
  &*& [1/2]gcf_instance<id, progress_t>(id_family(place_id(t3)), place_id(t3), nil);

lemma void split(place t1)
  requires split(t1, ?t2, ?t3) &*& token(t1, ?family);
  ensures token(t2, family) &*& token(t3, family);
{
  open split(t1, t2, t3);
  
  // show t1 and family are related.
  open token(t1, family);
  close token(t1, family);
  
  close token(t2, family);
  close token(t3, family);
}

lemma void join(place t1)
  requires join(t1, ?t2, ?t3) &*& token(t1, ?family) &*& token(t2, family);
  ensures token(t3, family);
{
  open join(t1, t2, t3);
  
  // show t1 and family are related.
  open token(t1, family);
  close token(t1, family);
  
  close token(t3, family);
}

// To create semi-anonymous lemmas using "produce_lemma_function_pointer_chunk(empty_lemma): some_lemma_typedef(....)(){...}"
lemma void empty_lemma()
  requires true;
  ensures true;
{
}

@*/

#endif
