<?php

/**
 * @file
 * Default theme implementation to display a node.
 *
 * Available variables:
 * - $title: the (sanitized) title of the node.
 * - $content: An array of node items. Use render($content) to print them all,
 *   or print a subset such as render($content['field_example']). Use
 *   hide($content['field_example']) to temporarily suppress the printing of a
 *   given element.
 * - $user_picture: The node author's picture from user-picture.tpl.php.
 * - $date: Formatted creation date. Preprocess functions can reformat it by
 *   calling format_date() with the desired parameters on the $created variable.
 * - $name: Themed username of node author output from theme_username().
 * - $node_url: Direct url of the current node.
 * - $display_submitted: Whether submission information should be displayed.
 * - $submitted: Submission information created from $name and $date during
 *   template_preprocess_node().
 * - $classes: String of classes that can be used to style contextually through
 *   CSS. It can be manipulated through the variable $classes_array from
 *   preprocess functions. The default values can be one or more of the
 *   following:
 *   - node: The current template type, i.e., "theming hook".
 *   - node-[type]: The current node type. For example, if the node is a
 *     "Article" it would result in "node-article". Note that the machine
 *     name will often be in a short form of the human readable label.
 *   - node-teaser: Nodes in teaser form.
 *   - node-preview: Nodes in preview mode.
 *   The following are controlled through the node publishing options.
 *   - node-promoted: Nodes promoted to the front page.
 *   - node-sticky: Nodes ordered above other non-sticky nodes in teaser
 *     listings.
 *   - node-unpublished: Unpublished nodes visible only to administrators.
 * - $title_prefix (array): An array containing additional output populated by
 *   modules, intended to be displayed in front of the main title tag that
 *   appears in the template.
 * - $title_suffix (array): An array containing additional output populated by
 *   modules, intended to be displayed after the main title tag that appears in
 *   the template.
 *
 * Other variables:
 * - $node: Full node object. Contains data that may not be safe.
 * - $type: Node type, i.e. page, article, etc.
 * - $comment_count: Number of comments attached to the node.
 * - $uid: User ID of the node author.
 * - $created: Time the node was published formatted in Unix timestamp.
 * - $classes_array: Array of html class attribute values. It is flattened
 *   into a string within the variable $classes.
 * - $zebra: Outputs either "even" or "odd". Useful for zebra striping in
 *   teaser listings.
 * - $id: Position of the node. Increments each time it's output.
 *
 * Node status variables:
 * - $view_mode: View mode, e.g. 'full', 'teaser'...
 * - $teaser: Flag for the teaser state (shortcut for $view_mode == 'teaser').
 * - $page: Flag for the full page state.
 * - $promote: Flag for front page promotion state.
 * - $sticky: Flags for sticky post setting.
 * - $status: Flag for published status.
 * - $comment: State of comment settings for the node.
 * - $readmore: Flags true if the teaser content of the node cannot hold the
 *   main body content.
 * - $is_front: Flags true when presented in the front page.
 * - $logged_in: Flags true when the current user is a logged-in member.
 * - $is_admin: Flags true when the current user is an administrator.
 *
 * Field variables: for each field instance attached to the node a corresponding
 * variable is defined, e.g. $node->body becomes $body. When needing to access
 * a field's raw values, developers/themers are strongly encouraged to use these
 * variables. Otherwise they will have to explicitly specify the desired field
 * language, e.g. $node->body['en'], thus overriding any language negotiation
 * rule that was previously applied.
 *
 * @see template_preprocess()
 * @see template_preprocess_node()
 * @see template_process()
 */
?>
<article<?php print $attributes; ?>>
  <header class="event-header">
    <?php print render($title_prefix); ?>
    <?php if (!$page): // teaser ?>
      <h2<?php print $title_attributes; ?>><a href="<?php print $node_url; ?>" rel="bookmark"><?php print $title; ?></a></h2>

    <?php else: // page ?>

      <?php if (isset($content['field_date']['#items'][0]['value'])): ?>
        <h2 class="event-date">
          <?php print date('l, F j, Y', strtotime($content['field_date']['#items'][0]['value'] . ' UTC')); ?>
        </h2>
      <?php endif; ?>

      <?php if (
        isset($content['field_venue'][0]['#title']) &&
        isset($content['field_venue']['#items'][0]['tid']) &&
        $content['field_venue']['#items'][0]['tid'] !== "1"
      ): ?>
        <h3 class="event-venue">
          At <?php print $content['field_venue'][0]['#title']; ?>
        </h3>
      <?php endif; ?>

      <h1 property="dc:title" class="node__title event-title">
        <?php print $title; ?>
        <?php if (isset($content['field_coheadlining_act']['#items'])): ?>
          <?php foreach ($content['field_coheadlining_act']['#items'] as $key => $item): ?>
            <?php print ' <span class="delimiter">//</span> ' . $item['safe_value']; ?>
          <?php endforeach; ?>
        <?php endif; ?>
      </h1>

      <?php if (isset($content['field_special_guest']['#items'])): ?>
        <div class="event-special-guest">
          <span class="event-special-guest-label event-header-label">
            With Special Guest<?php if (count($content['field_special_guest']['#items']) > 1) print 's';?>:
          </span>
          <?php foreach ($content['field_special_guest']['#items'] as $key => $item): ?>
            <?php if ($key !== 0) print ' <span class="delimiter">//</span> '; ?>
            <?php print $item['safe_value']; ?>
          <?php endforeach; ?>
        </div>
      <?php endif; ?>

      <?php if (isset($content['field_opener']['#items'])): ?>
        <div class="event-opener">
          <span class="event-opener-label event-header-label">
            Opener<?php if (count($content['field_opener']['#items']) > 1) print 's';?>:
          </span>
          <?php foreach ($content['field_opener']['#items'] as $key => $item): ?>
            <?php if ($key !== 0) print ' <span class="delimiter">//</span> '; ?>
            <?php print $item['safe_value']; ?>
          <?php endforeach; ?>
        </div>
      <?php endif; ?>

      <?php if (
        isset($content['field_ticket_url']['#items']) &&
        isset($content['field_ticket_url']['#items'][0]['url']) &&
        strpos($content['field_ticket_url']['#items'][0]['url'], 'null') === false &&
        isset($content['field_date']['#items'][0]['value']) &&
        strtotime($content['field_date']['#items'][0]['value'] . ' UTC') >= time()
      ): ?>
        <div class="event-tickets">
        <?php foreach ($content['field_ticket_url']['#items'] as $key => $item): ?>
          <?php if (
            isset($content['field_sold_out']['#items'][0]['value']) &&
            $content['field_sold_out']['#items'][0]['value'] === '1'
          ) {
            $item['attributes']['class'] = array('event-tickets-link--sold-out');
            $item['title'] = 'Sold Out';
          } else {
            $item['attributes']['class'] = array('event-tickets-link');
          } ?>
          <?php print l($item['title'], $item['url'], array(
            'attributes' => $item['attributes'],
            'html' => true,
            'query' => $item['query'],
          )); ?>
        <?php endforeach; ?>
        </div>
      <?php endif; ?>

      <ul class="event-time-list">
        <?php if (
          isset($content['field_date_tickets'][0]['#markup']) &&
          isset($content['field_date_tickets']['#items'][0]['value']) &&
          strtotime($content['field_date_tickets']['#items'][0]['value'] . ' UTC') >= time()
        ): ?>
          <li class="event-time-item event-time-tickets">
            <span class="event-header-label">Tickets On-sale:</span>
            <?php print $content['field_date_tickets'][0]['#markup']; ?>
          </li>
        <?php endif; ?>
        <?php if (isset($content['field_date_doors'][0]['#markup'])): ?>
          <li class="event-time-item event-time-doors">
            <span class="event-header-label">Doors Open:</span>
            <?php print $content['field_date_doors'][0]['#markup']; ?>
          </li>
        <?php endif; ?>
        <?php if (isset($content['field_date'][0]['#markup'])): ?>
          <li class="event-time-item event-time-show">
            <span class="event-header-label">Show Starts:</span>
            <?php print $content['field_date'][0]['#markup']; ?>
          </li>
        <?php endif; ?>
        <?php if (isset($content['field_price_display'][0]['#markup'])): ?>
          <li class="event-time-item event-price">
            <span class="event-header-label">Ticket Price:</span>
            <?php print $content['field_price_display'][0]['#markup']; ?>
          </li>
        <?php endif; ?>
      </ul>

      <?php if (
        isset($content['field_genre']['#items']) &&
        count($content['field_genre']['#items'] > 0)
        ): ?>
        <ul class="event-genre-list">
          <?php foreach($content['field_genre']['#items'] as $key => $genre): ?>
            <?php $genre_name = isset($genre['tid']) ?
            taxonomy_term_load($genre['tid'])->name :
            ''; ?>
            <li class="event-genre-item">
              <?php if ($key === 0): ?>
                <span class="event-header-label">Genre:</span>
              <?php endif; ?>
              <?php print $genre_name; ?>
            </li>
          <?php endforeach; ?>
        </ul>
      <?php endif; ?>

      <nav class="event-navigation">
        <ul class="event-navigation-list">
          <li class="event-navigation-item">
            <?php if (
              !isset($node->field_doors_only['und'][0]['value']) ||
              $node->field_doors_only['und'][0]['value'] !== '1'
            ): ?>
              <a class="event-navigation-link" href="/shows-events/ticket-information"><?php print t('Buy Tickets in Person'); ?></a>
            <?php else: ?>
              <a class="event-navigation-link" href="/shows-events/ticket-information"><?php print t('Tickets Sold at the Door'); ?></a>
            <?php endif; ?>
          </li>
          <?php if (isset($content['field_venue']['#items'][0]['tid'])): ?>
            <?php $term = taxonomy_term_load($content['field_venue']['#items'][0]['tid']); ?>
            <?php if (isset($term->field_seating_url['und'][0]['url'])): ?>
              <li class="event-navigation-item">
                <?php $link = $term->field_seating_url['und'][0]; ?>
                <?php $link['attributes']['class'] = array('event-navigation-link'); ?>
                <?php print l($link['title'], $link['url'], array(
                  'attributes' => $link['attributes']
                )); ?>
              </li>
            <?php endif; ?>
          <?php endif; ?>
          <?php if (isset($content['field_link']['#items'])): ?>
            <?php foreach ($content['field_link']['#items'] as $link): ?>
              <?php $link['attributes']['class'] = array('event-navigation-link'); ?>
              <li class="event-navigation-item">
                <?php print l($link['title'], $link['url'], array(
                  'attributes' => $link['attributes'],
                  'html' => true,
                )); ?>
              </li>
            <?php endforeach; ?>
          <?php endif; ?>
        </ul>
      </nav>

    <?php endif; ?>
    <?php print render($title_suffix); ?>
  </header>

  <div class="node__content event-content">
    <?php if (isset($content['field_endorsement'][0]['#markup'])): ?>
      <div class="event-endorsement">
        <div class="event-endorsement-body">
          <?php print str_replace(
            '<p',
            '<p class="event-endorsement-paragraph"',
            $content['field_endorsement'][0]['#markup']
          ); ?>
        </div>
        <?php if (isset($content['field_endorsement_source'][0]['#markup'])): ?>
          <div class="event-endorsement-source">
            <?php print str_replace(
              '<p',
              '<p class="event-endorsement-paragraph"',
              $content['field_endorsement_source'][0]['#markup']);
            ?>
          </div>
        <?php endif; ?>
      </div>
    <?php endif; ?>

    <div class="event-content-primary">
      <?php if (isset($content['body'][0]['#markup'])): ?>
        <section class="event-body">
          <h2 class="event-media-title expander">Description</h2>
          <div class="event-body-content expander-content">
            <?php print str_replace(
              '<p',
              '<p class="event-body-paragraph"',
              $content['body'][0]['#markup']);
            ?>
          </div>
        </section>
      <?php endif; ?>

      <?php if (isset($content['field_media']) || isset($content['field_spotify_uri'])): ?>
        <section class="event-media">
          <h2 class="event-media-title expander">Photos &amp; Videos</h2>
          <div class="event-media-content expander-content">
            <?php if (isset($content['field_media']['#items'])): ?>
              <div class="event-images-videos">
                <?php foreach ($content['field_media']['#items'] as $key => $item): ?>
                  <?php if ($item['type'] === 'image' && isset($content['field_media'][$key]['file'])) {
                    $content['field_media'][$key]['file']['#image_style'] = 'event_image';
                  }
                  elseif (isset($content['field_media'][$key]['file']['#options'])) {
                    $content['field_media'][$key]['file']['#options']['width'] = '580';
                    $content['field_media'][$key]['file']['#options']['height'] = '365';
                  } ?>
                  <?php print render($content['field_media'][$key]); ?>
                <?php endforeach; ?>
              </div>
            <?php endif; ?>

            <?php if (isset($content['field_spotify_uri'])): ?>
              <div class="event-spotify">
                <?php print render($content['field_spotify_uri']); ?>
              </div>
            <?php endif; ?>
          </div>
        </section>
      <?php endif; ?>
    </div>

    <?php if (isset($content['field_sponsor']['#items'])): ?>
      <section class="event-sponsors">
        <h2 class="event-sponsors-title">Presented with support from</h2>
        <ul class="event-sponsors-list">
          <?php foreach ($content['field_sponsor']['#items'] as $key => $item): ?>
            <li class="event-sponsors-list-item">
              <?php $term = taxonomy_term_load($item['target_id']); ?>
              <?php if (isset($term->field_link_sponsor['und'][0]['url'])): ?>
                <a class="event-sponsors-sponsor-link" href="<?php print $term->field_link_sponsor['und'][0]['url']; ?>" target="_blank">
              <?php endif; ?>
              <?php if (isset($term->field_image['und'][0]) && isset($term->field_image['und'][0]['uri'])): ?>
                <?php
                  $image = $term->field_image['und'][0];
                  print theme('image_style', array(
                    'alt' => $image['alt'],
                    'path' => $image['uri'],
                    'style_name' => 'sponsor',
                    'title' => $image['title'],
                    'attributes' => array(
                      'class' => array(
                        'event-sponsors-sponsor-image',
                      ),
                    )
                  ));
                ?>
              <?php else: ?>
                <span class="event-sponsors-sponsor-name"><?php print $term->name; ?></span>
              <?php endif; ?>
              <?php if (isset($term->field_link_sponsor['und'][0]['url'])): ?>
                </a>
              <?php endif; ?>
            </li>
          <?php endforeach; ?>
        </ul>
      </section>
    <?php endif; ?>

    <div class="event-social">
      <a class="event-social-button button-social facebook-share"
        href="<?php print $GLOBALS['base_url'] . '/' . request_path(); ?>"
        role="button"
        <?php if (isset($content['body'][0]['#markup']))
          print 'data-description="' . strip_tags(text_summary($content['body'][0]['#markup'], null, 300)) . '"'; ?>
        <?php if (isset($content['field_image']['#items'][0]['uri']))
          print 'data-image="' . file_create_url($content['field_image']['#items'][0]['uri']) . '"'; ?>
        data-title="<?php print $title; ?>">Share</a>
      <a class="event-social-button button-social twitter-tweet"
        href="https://twitter.com/share?url=<?php print $GLOBALS['base_url'] . '/' . request_path(); ?>"
        role="button">Tweet</a>
    </div>

  </div>
<!-- related artists/events -->
<?php if(isset($content['field_related_event'][0])): ?>
    <div class="block-related-pages related-event-wrap">
    <div class="related-pages-links">
    <?php if(!empty($content['field_related_event']['#object']->field_related_event['und'])): ?>
        <?php foreach($content['field_related_event']['#object']->field_related_event['und'] as $related_event): ?>
        <a href="<?php print url('node/'.$related_event['target_id']); ?>">
            <?php echo $related_event['entity']->title; ?>
        </a> 
        <?php if(next($content['field_related_event']['#object']->field_related_event['und'])): ?> 
         | <!-- we don't display the pipe if it's the last loop -->
        <?php endif; ?>
        <?php endforeach; ?>
    <?php endif; ?>
    </div>
    </div>
<?php endif; ?>
  <?php print render($content['links']); ?>
  <?php print render($content['comments']); ?>
</article>
