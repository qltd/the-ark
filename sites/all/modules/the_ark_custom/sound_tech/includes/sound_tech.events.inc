<?php

function sound_tech_edit_event ($nid) {
  $event = node_load($nid);
  if (!(isset($event->type) && $event->type === 'event')) return drupal_not_found();
  $query = new EntityFieldQuery();
  $results = $query
    ->entityCondition('entity_type', 'node')
    ->propertyCondition('type', 'sound_tech')
    ->propertyCondition('status', 1)
    ->fieldCondition('field_event', 'target_id', $nid, '=')
    ->execute();
  if (isset($results['node'])) {
    $sound_tech_event = end($results['node']);
  } else {
    $event_title = $event->title;
    $co_headlining_acts = isset($event->field_coheadlining_act['und'])
      ? $event->field_coheadlining_act['und']
      : array();

    if (count($co_headlining_acts) !== 0) {
      foreach ($co_headlining_acts as $key => $act) {
        $event_title .= ' // ' . $act['safe_value'];
      }
    }

    global $user;

    $sound_tech_event = (object) null;
    $sound_tech_event->type = 'sound_tech';
    $sound_tech_event->uid = $user->uid;
    $sound_tech_event->created = strtotime("now");
    $sound_tech_event->changed = strtotime("now");
    $sound_tech_event->status = 1;
    $sound_tech_event->comment = 0;
    $sound_tech_event->promote = 0;
    $sound_tech_event->moderate = 0;
    $sound_tech_event->sticky = 0;
    $sound_tech_event->language = 'und';
    $sound_tech_event->title = $event_title;
    $sound_tech_event->field_event['und'][0]['target_id'] = $nid;
    node_save($sound_tech_event);
  }

  if (!isset($sound_tech_event->nid)) return drupal_not_found();

  $options = array();
  $options['query'] = array();
  $options['query']['destination'] = 'admin/sound-tech/events';
  if (isset($event->field_date['und'][0]['value'])) {
    $options['query']['field_date'] = strtotime($event->field_date['und'][0]['value']);
  }

  return drupal_goto('node/'. $sound_tech_event->nid . '/edit', $options);
}
